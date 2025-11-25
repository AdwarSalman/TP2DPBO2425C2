import express from "express";
import cors from "cors";
import route from "./routes/route.js";
import path from "path";
import dotenv from "dotenv";
import { fileURLToPath } from "url";
import AuthRoute from "./routes/AuthRoute.js"
import newsRoute from "./routes/newsRoute.js"
import UserRoute from "./routes/User.js"

// Import database (opsional di sini jika hanya digunakan di route, 
// tapi bagus untuk memastikan db terinisialisasi)
import db from "./db.js";

dotenv.config();
const app = express();

app.use(cors());

// Untuk menerima JSON biasa
app.use(express.json());

app.use("/api/auth", AuthRoute)

// Daftar routes
app.use("/api", route);
app.use("/api", newsRoute);
app.use("/api", UserRoute);

// Untuk menerima form-data + foto, kita tambahkan folder upload
app.use("/uploads", express.static("uploads"));
const IMAGE_PATH = path.join(process.cwd(), "images");
app.use("/images", express.static(IMAGE_PATH));

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => console.log(`🚀 Server running on port ${PORT}`));
