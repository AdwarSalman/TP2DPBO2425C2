<template>
  <div class="relative z-10 p-6 mt-20 bg-gray-50 min-h-screen">
    <!-- Tombol Switch + Search + Filter -->
    <div class="flex flex-wrap items-center space-x-4 mb-6 relative z-20">
      <button
        @click="changeType('Kucing')"
        :class="[currentType === 'Kucing'
            ? 'bg-gray-400 text-white shadow-md'
            : 'bg-gray-200 text-gray-700 hover:bg-gray-300',
          'px-4 py-2 rounded-lg text-sm font-semibold transition duration-150 ease-in-out focus:outline-none']"
      >
        Kucing
      </button>

      <button
        @click="changeType('User')"
        :class="[currentType === 'User'
            ? 'bg-gray-400 text-white shadow-md'
            : 'bg-gray-200 text-gray-700 hover:bg-gray-300',
          'px-4 py-2 rounded-lg text-sm font-semibold transition duration-150 ease-in-out focus:outline-none']"
      >
        User
      </button>

      <!-- Search Box -->
      <div class="relative flex-grow max-w-lg">
        <input
          type="text"
          v-model="searchQuery"
          placeholder="Search..."
          class="w-full pl-10 pr-4 py-2 rounded-lg border-none focus:ring-1 focus:ring-gray-500 bg-gray-200 placeholder-gray-500"
        />
        <svg
          class="absolute left-3 top-1/2 transform -translate-y-1/2 h-5 w-5 text-gray-500"
          fill="none"
          stroke="currentColor"
          viewBox="0 0 24 24"
        >
          <path
            stroke-linecap="round"
            stroke-linejoin="round"
            stroke-width="2"
            d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z"
          />
        </svg>
      </div>

      <!-- Filter -->
      <div class="relative">
        <button
          class="flex items-center px-4 py-2 bg-gray-200 rounded-lg text-sm font-semibold text-gray-700 hover:bg-gray-300 focus:outline-none"
        >
          Filter
          <svg
            class="ml-2 h-4 w-4"
            fill="none"
            stroke="currentColor"
            viewBox="0 0 24 24"
          >
            <path
              stroke-linecap="round"
              stroke-linejoin="round"
              stroke-width="2"
              d="M19 9l-7 7-7-7"
            />
          </svg>
        </button>
      </div>
    </div>

    <!-- Tabel Data -->
    <div class="bg-white shadow overflow-hidden sm:rounded-lg relative z-10">
      <div class="overflow-x-auto">
        <table class="min-w-full divide-y divide-gray-200">
          <thead class="bg-gray-50">
            <tr>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">ID</th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">Gambar</th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">Nama</th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">
                {{ currentType === 'Kucing' ? 'Jenis' : 'Peran' }}
              </th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">
                {{ currentType === 'Kucing' ? 'Umur' : 'Kontak' }}
              </th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">Kota</th>
              <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">Aksi</th>
            </tr>
          </thead>

          <tbody class="bg-white divide-y divide-gray-200">
            <tr
              v-for="item in filteredData"
              :key="item.id + item.name"
              class="hover:bg-gray-50"
            >
              <td class="px-6 py-4 text-sm font-medium text-gray-900">{{ item.id }}</td>

              <td class="px-6 py-4 whitespace-nowrap">
                <div class="flex items-center">
                  <div class="flex-shrink-0 h-10 w-10">
                    <img
                      v-if="item.img"
                      :src="item.img"
                      :alt="item.name"
                      class="h-10 w-10 rounded-full object-cover"
                    />
                    <div
                      v-else
                      class="h-10 w-10 rounded-full bg-gray-300 flex items-center justify-center text-white"
                    >
                      <span v-if="currentType === 'User'">👤</span>
                      <span v-else>🐾</span>
                    </div>
                  </div>
                </div>
              </td>

              <td class="px-6 py-4 text-sm text-gray-500">{{ item.name }}</td>
              <td class="px-6 py-4 text-sm text-gray-500">{{ currentType === 'Kucing' ? item.breed : item.role }}</td>
              <td class="px-6 py-4 text-sm text-gray-500">{{ currentType === 'Kucing' ? item.age : item.contact }}</td>
              <td class="px-6 py-4 text-sm text-gray-500">{{ item.location }}</td>

              <td class="px-6 py-4 whitespace-nowrap text-sm flex space-x-2">
                <span class="text-indigo-600 cursor-pointer hover:text-indigo-900" @click="handleAction('Detail', item)">Detail</span>
                <button @click="handleAction('Edit', item)" class="text-gray-400 hover:text-gray-700">
                  ✏️
                </button>
                <button @click="handleAction('Delete', item)" class="text-gray-400 hover:text-gray-700">
                  🗑️
                </button>
              </td>
            </tr>
          </tbody>
        </table>
      </div>
    </div>

    <!-- Tombol Mengambang -->
    <div class="fixed bottom-6 right-6 flex flex-col space-y-3 z-30">
      <!-- Report Button -->
      <button
        @click="handleReport"
        class="flex items-center space-x-2 px-4 py-2 bg-red-400 text-white rounded-full shadow-lg hover:bg-red-500 focus:outline-none"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2"
            d="M12 8v4m0 4h.01M21 12A9 9 0 113 12a9 9 0 0118 0z"/>
        </svg>
        <span>Report</span>
      </button>

      <!-- Donasi Button -->
      <button
        @click="handleDonate"
        class="flex items-center space-x-2 px-4 py-2 bg-green-400 text-white rounded-full shadow-lg hover:bg-green-500 focus:outline-none"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2"
            d="M12 8c-1.657 0-3 1.567-3 3.5S10.343 15 12 15s3-1.567 3-3.5S13.657 8 12 8z" />
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2"
            d="M4 12a8 8 0 0116 0v4a4 4 0 01-8 0" />
        </svg>
        <span>Donasi</span>
      </button>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, onMounted } from "vue";
import axios from "axios";

const catData = ref([]);

onMounted(async () => {
  try {
    const res = await axios.get("http://localhost:5000/api/reports");

    catData.value = res.data.map(r => {
      let photo = null;

      try {
        const arr = JSON.parse(r.image);
        photo = arr.length > 0 ? `http://localhost:5000/uploads/${arr[0]}` : null;
      } catch (e) {
        photo = null;
      }

      return {
        id: r.id,
        img: photo,
        name: r.name,
        breed: r.breeds,
        age: r.age,
        location: r.lastLocation
      };
    });
  } catch (err) {
    console.error("Gagal mengambil data reports:", err);
  }
});


const userData = ref([
  { id: "#001", img: "https://i.imgur.com/3YfB0yv.jpg", name: "Ujang", role: "Adapter", contact: "089158139581", location: "Bandung" },
  { id: "#002", img: null, name: "Siti", role: "Donatur", contact: "081234567890", location: "Surabaya" },
]);

const currentType = ref("Kucing");
const searchQuery = ref("");

const tableData = computed(() => (currentType.value === "Kucing" ? catData.value : userData.value));

const filteredData = computed(() => {
  if (!searchQuery.value) return tableData.value;
  const query = searchQuery.value.toLowerCase();
  return tableData.value.filter((item) => {
    const fields = [item.id, item.name, item.location];
    if (currentType.value === "Kucing") fields.push(item.breed, item.age);
    else fields.push(item.role, item.contact);
    return fields.some((val) => String(val).toLowerCase().includes(query));
  });
});

const changeType = (newType) => {
  currentType.value = newType;
  searchQuery.value = "";
};

const handleAction = (action, item) => {
  alert(`Anda memilih ${action} untuk ${item.name} (${item.id})`);
};

const handleReport = () => {
  alert("Ada laporan baru! Admin akan segera meninjau data report.");
  console.log("Report dikirim ke admin ✅");
};

const handleDonate = () => {
  alert("Terima kasih atas donasinya! Admin akan mencatat transaksi ini.");
  console.log("Donasi diterima oleh admin 💚");
};
</script>

