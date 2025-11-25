// src/composables/useAuth.js
import { ref, computed } from "vue";
import axios from "axios";

const storedUser = localStorage.getItem("user");
const storedToken = localStorage.getItem("token");

const user = ref(storedUser ? JSON.parse(storedUser) : null);
const token = ref(storedToken || null);

// kalau ada token saat app start, set default header axios
if (token.value) {
  axios.defaults.headers.common["Authorization"] = `Bearer ${token.value}`;
}

function setAuth(newUser, newToken) {
  user.value = newUser || null;
  token.value = newToken || null;

  if (newUser) localStorage.setItem("user", JSON.stringify(newUser));
  else localStorage.removeItem("user");

  if (newToken) {
    localStorage.setItem("token", newToken);
    axios.defaults.headers.common["Authorization"] = `Bearer ${newToken}`;
  } else {
    localStorage.removeItem("token");
    delete axios.defaults.headers.common["Authorization"];
  }
}

function logout() {
  setAuth(null, null);
}

const isLoggedIn = computed(() => !!token.value);

export function useAuth() {
  return {
    user,
    token,
    isLoggedIn,
    setAuth,
    logout,
  };
}
