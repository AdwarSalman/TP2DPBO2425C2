import './assets/main.css'

import { createApp } from 'vue'
import App from './App.vue'
import router from './router'

// GLOBAL AXIOS
import axios from 'axios'

// 🔧 Set base URL default ke /api di backend
axios.defaults.baseURL = 'http://localhost:5000/api';

const app = createApp(App)
app.config.globalProperties.$axios = axios

app.use(router)
app.mount('#app')
