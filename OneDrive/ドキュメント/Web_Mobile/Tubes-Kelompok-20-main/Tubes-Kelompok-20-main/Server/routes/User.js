import express from "express";
import db from "../db.js"; // Ubah dari { db } menjadi db (default import)
import { authenticateToken } from "./AuthRoute.js"; // Ini sekarang akan berhasil

const router = express.Router();

// GET user profile
router.get("/profile/:id", authenticateToken, async (req, res) => {
  try {
    const userId = req.params.id;
    // Pastikan query menggunakan db.query (promise based dari mysql2)
    const [rows] = await db.query(
      `SELECT id, name, username, dob, nik, selter, email, phone FROM users WHERE id = ?`,
      [userId]
    );
    
    if (!rows.length) return res.status(404).json({ error: "User not found" });
    res.json(rows[0]);
  } catch (err) {
    console.error("Get Profile Error:", err);
    res.status(500).json({ error: "Server error" });
  }
});

// UPDATE profile
router.put("/profile/:id", authenticateToken, async (req, res) => {
  try {
    const userId = req.params.id;
    const { name, username, dob, nik, selter, email, phone } = req.body;

    const [result] = await db.query(
      `UPDATE users 
       SET name = ?, username = ?, dob = ?, nik = ?, selter = ?, email = ?, phone = ?
       WHERE id = ?`,
      [name, username, dob, nik, selter, email, phone, userId]
    );

    if (result.affectedRows === 0) return res.status(404).json({ error: "User not found" });

    // Return updated user data
    const [updatedRows] = await db.query(
      `SELECT id, name, username, dob, nik, selter, email, phone FROM users WHERE id = ?`,
      [userId]
    );

    res.json({ success: true, user: updatedRows[0] });
  } catch (err) {
    console.error("Update Profile Error:", err);
    res.status(500).json({ error: "Server error" });
  }
});

export default router;  