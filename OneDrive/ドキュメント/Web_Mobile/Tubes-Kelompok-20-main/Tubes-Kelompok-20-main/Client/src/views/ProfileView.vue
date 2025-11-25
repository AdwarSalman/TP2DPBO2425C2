<script setup>
import { ref, onMounted } from 'vue'
import { useAuth } from '@/composables/useAuth'
import { AuthApi } from '@/api/authApi'

const { user, setUser } = useAuth()

// editing mode
const isEditing = ref(false)
const tempUser = ref({})

// form fields
const name = ref('')
const username = ref('')
const dob = ref('')
const nik = ref('')
const selter = ref('')
const email = ref('')
const phone = ref('')

// load user data
onMounted(() => {
  if (user.value) {
    name.value = user.value.name || ''
    username.value = user.value.username || ''
    dob.value = user.value.dob || ''
    nik.value = user.value.nik || ''
    selter.value = user.value.selter || ''
    email.value = user.value.email || ''
    phone.value = user.value.phone || ''
  }
})

// start edit
function startEdit() {
  tempUser.value = { ...user.value }
  isEditing.value = true
}

// cancel edit
function cancelEdit() {
  if (tempUser.value) {
    name.value = tempUser.value.name
    username.value = tempUser.value.username
    dob.value = tempUser.value.dob
    nik.value = tempUser.value.nik
    selter.value = tempUser.value.selter
    email.value = tempUser.value.email
    phone.value = tempUser.value.phone
  }
  isEditing.value = false
}

// save profile (backend + useAuth)
async function saveProfile() {
  try {
    const res = await AuthApi.updateProfile({
      id: user.value.id,
      name: name.value,
      username: username.value,
      dob: dob.value,
      nik: nik.value,
      selter: selter.value,
      email: email.value,
      phone: phone.value
    })
    if (res.data.success) {
      setUser(res.data.user)
      alert('Profile updated successfully!')
      isEditing.value = false
    } else {
      alert(res.data.error || 'Failed to update profile')
    }
  } catch (err) {
    console.error(err)
    alert('Server error, try again later')
  }
}
</script>

<template>
  <div class="bg-[#f7f1e8] min-h-screen flex flex-col items-center pt-16">
    <div class="relative bg-[#fef5dd] rounded-[25px] w-11/12 max-w-md shadow-lg overflow-visible">
      
      <!-- cat image -->
      <img src="/images/vector/kucingsetengah.PNG" class="absolute -top-16 left-1/2 -translate-x-1/2 w-30 z-10" />

      <!-- header -->
      <div class="bg-[#ED8B3C] rounded-t-[25px] text-center py-16 px-5 relative z-1">
        <h1 class="text-2xl font-bold text-[#1c1c1c] mb-16">User Profile</h1>
        <div class="absolute -bottom-16 left-1/2 -translate-x-1/2 text-center z-5">
          <img src="/images/vector/gabriel.svg" class="w-28 h-28 rounded-full border-4 border-[#fef5dd] object-cover" />
          <p class="mt-2 text-sm text-gray-700">Profile Picture</p>
        </div>
      </div>

      <!-- view mode -->
      <div v-if="!isEditing" class="mt-20 flex flex-col gap-2 px-6 pb-7">
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Name</strong><span>{{ name }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Username</strong><span>{{ username }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Date of Birth</strong><span>{{ dob }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>NIK</strong><span>{{ nik }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Selter</strong><span>{{ selter }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Email</strong><span>{{ email }}</span>
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>No HP</strong><span>{{ phone }}</span>
        </div>

        <button @click="startEdit" class="mt-6 px-5 py-2 bg-blue-600 text-white rounded-lg hover:bg-blue-700 transition">
          Edit Profile
        </button>
      </div>

      <!-- edit mode -->
      <div v-else class="mt-20 flex flex-col gap-2 px-6 pb-7">
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Name</strong>
          <input v-model="name" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Username</strong>
          <input v-model="username" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Date of Birth</strong>
          <input v-model="dob" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>NIK</strong>
          <input v-model="nik" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Selter</strong>
          <input v-model="selter" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>Email</strong>
          <input v-model="email" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>
        <div class="flex justify-between bg-[#fff8ee] rounded-lg px-3 py-2 text-gray-700 text-sm">
          <strong>No HP</strong>
          <input v-model="phone" class="bg-transparent border-b border-gray-300 text-right text-sm outline-none w-3/5" />
        </div>

        <div class="flex gap-3 mt-6">
          <button @click="saveProfile" class="px-5 py-2 bg-green-600 text-white rounded-lg hover:bg-green-700 transition">
            Save
          </button>
          <button @click="cancelEdit" class="px-5 py-2 bg-gray-400 text-white rounded-lg hover:bg-gray-500 transition">
            Cancel
          </button>
        </div>
      </div>
    </div>
  </div>
</template>
