<script setup>
import Navbar from './components/navbar.vue'
import { RouterView } from 'vue-router'
import { ref, onMounted } from 'vue'

</script>

<template>
  <Navbar />
  <RouterView />
</template>

<style scoped>
/* Styling sederhana */
</style>
