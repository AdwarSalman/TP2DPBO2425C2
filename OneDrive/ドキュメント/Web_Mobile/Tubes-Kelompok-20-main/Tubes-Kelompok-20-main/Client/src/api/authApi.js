import api from "./api"; // Import instance axios yang sudah disetting base URL

export const AuthApi = {
  signup(data) {
    // Mengarah ke: http://localhost:5000/api/auth/signup
    return api.post("/auth/signup", data); 
  },
  login(data) {
    // Mengarah ke: http://localhost:5000/api/auth/login
    return api.post("/auth/login", data);
  }
};