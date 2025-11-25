import express from "express";
import db from "../db.js";
import bcrypt from "bcrypt";
import jwt from "jsonwebtoken";

const router = express.Router();

// ✅ MIDDLEWARE (Opsional, simpan untuk nanti)
export const authenticateToken = (req, res, next) => {
  const authHeader = req.headers['authorization'];
  const token = authHeader && authHeader.split(' ')[1];
  if (!token) return res.status(401).json({ error: "Akses ditolak" });

  jwt.verify(token, process.env.JWT_SECRET || "secret_key", (err, user) => {
    if (err) return res.status(403).json({ error: "Token tidak valid" });
    req.user = user;
    next();
  });
};

// ✅ SIGNUP (FIXED)
router.post("/signup", async (req, res) => {
  try {
    const { name, email, password } = req.body;

    // 1. Cek apakah email sudah ada
    const [existingUser] = await db.query("SELECT * FROM users WHERE email = ?", [email]);
    if (existingUser.length > 0) {
      return res.status(400).json({ error: "Email sudah terdaftar" });
    }

    // 2. Hash Password
    const hashed = await bcrypt.hash(password, 10);

    // 3. Insert Data (TAMBAHKAN role_id = 2 untuk User)
    const sql = `
        INSERT INTO users (name, email, password, role_id)
        VALUES (?, ?, ?, ?)
    `;
    
    // Kita masukkan '2' sebagai default role_id (User)
    await db.query(sql, [name, email, hashed, 2]);

    res.json({ success: true, message: "Registrasi berhasil" });

  } catch (err) {
    console.error("Signup Error:", err);
    res.status(500).json({ error: "Gagal mendaftar user", details: err.message });
  }
});

// ✅ LOGIN (Sudah diperbaiki sebelumnya, pastikan konsisten)
router.post("/login", async (req, res) => {
  try {
    const { email, password } = req.body;
    if (!email || !password) return res.status(400).json({ error: "Email & Password wajib" });

    const [rows] = await db.query("SELECT * FROM users WHERE email = ?", [email]);
    if (rows.length === 0) return res.status(400).json({ error: "Email tidak ditemukan" });

    const user = rows[0];

    // Bandingkan password Hash
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) return res.status(400).json({ error: "Password salah" });

    const token = jwt.sign(
      { id: user.id, email: user.email, role: user.role_id },
      process.env.JWT_SECRET || "secret_key",
      { expiresIn: "1d" }
    );

    res.json({
      message: "Login berhasil",
      token,
      user: {
        id: user.id,
        name: user.name,
        email: user.email,
        role_id: user.role_id
      }
    });

  } catch (err) {
    console.error("Login Error:", err);
    res.status(500).json({ error: "Server error" });
  }
});

export default router;