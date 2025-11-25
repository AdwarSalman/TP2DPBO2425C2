<template>
  <main class="min-h-screen bg-[#f7f1e8] p-4 sm:p-8 relative overflow-hidden">
    <div class="max-w-4xl mx-auto z-10 relative">
      <!-- Judul -->
      <div class="text-center mb-8 pt-10">
        <h1 class="text-4xl sm:text-5xl font-extrabold text-[#2a2a2a] pt-20">Report & Rescue</h1>
        <h2 class="text-3xl sm:text-4xl font-extrabold text-[#2a2a2a]">Kitten</h2>
      </div>

      <!-- Form -->
      <form
        @submit.prevent="submitReport"
        class="bg-[#2a2a2a] p-6 sm:p-10 rounded-3xl shadow-2xl space-y-6 border border-[#3d3d3d]"
      >
        <!-- Upload Foto -->
      <!-- Perbaruan di bagian agar foto tertampil di form saat user add laporam -->
       <div
          class="bg-[#3b3b3b] p-6 rounded-xl text-center shadow-inner border border-[#4a4a4a]"
        >
          <!-- Jika belum upload foto -->
          <label v-if="previewImages.length === 0" for="photos" class="cursor-pointer">
            <svg
              xmlns="http://www.w3.org/2000/svg"
              class="h-10 w-10 mx-auto text-[#d4b97d]"
              fill="none"
              viewBox="0 0 24 24"
              stroke="currentColor"
              stroke-width="2"
            >
              <path
                stroke-linecap="round"
                stroke-linejoin="round"
                d="M3 9a2 2 0 012-2h.9a2 2 0 001.6-.8l.7-1.4A2 2 0 0110 4h4a2 2 0 011.6.8l.7 1.4a2 2 0 001.6.8H19a2 2 0 012 2v8a2 2 0-01-2 2H5a2 2 0-01-2-2V9z"
              />
              <path
                stroke-linecap="round"
                stroke-linejoin="round"
                d="M15 13a3 3 0 11-6 0 3 3 0 016 0z"
              />
            </svg>
            <p class="text-[#e6dccb] font-semibold mt-2">Upload Photos</p>
          </label>

          <!-- Jika foto sudah diupload, tampilkan preview -->
          <div v-else class="grid grid-cols-2 gap-3 mt-3">
            <div v-for="(src, i) in previewImages" :key="i">
              <img :src="src" class="w-full h-40 object-cover rounded-lg border border-[#666]" />
            </div>
          </div>

          <input
            type="file"
            id="photos"
            @change="handleFileUpload"
            multiple
            class="hidden"
            accept="image/*"
          />
        </div>


        <!-- Input fields -->
        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Name</span>
          <input
            v-model="form.name"
            type="text"
            placeholder="Nama Kucing (jika tahu)"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
            required
          />
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Age</span>
          <input
            v-model="form.age"
            type="text"
            placeholder="Estimasi Umur"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
            required
          />
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Gender</span>
          <select
            v-model="form.gender"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
          >
            <option value="" disabled>Pilih Jenis Kelamin</option>
            <option value="Jantan">Jantan</option>
            <option value="Betina">Betina</option>
            <option value="Tidak Tahu">Tidak Tahu</option>
          </select>
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Breeds</span>
          <input
            v-model="form.breeds"
            type="text"
            placeholder="Ras (Domestik/Persia/dll.)"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
          />
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Reporter's contact</span>
          <input
            v-model="form.reporterContact"
            type="tel"
            placeholder="Nomor Telepon/Email"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
            required
          />
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Last Location</span>
          <input
            v-model="form.lastLocation"
            type="text"
            placeholder="Alamat/Deskripsi Lokasi"
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all mb-4"
            required
          />
          <div class="h-40 bg-[#444] rounded-lg overflow-hidden shadow-md flex items-center justify-center">
            <p class="p-4 text-sm text-[#bfbfbf] text-center">
              Placeholder Peta - Integrasi Map API akan dilakukan di sini
            </p>
          </div>
        </label>

        <label class="block">
          <span class="text-[#e6dccb] font-semibold">Description</span>
          <textarea
            v-model="form.description"
            rows="4"
            placeholder="Jelaskan kondisi kucing, ciri-ciri khusus, dan perilaku."
            class="w-full mt-2 p-3 text-[#f1e7d0] bg-[#3b3b3b] border-none rounded-md shadow-sm 
                   focus:ring-[#d4b97d] focus:border-[#d4b97d] placeholder-[#c6bfae] transition-all"
            required
          ></textarea>
        </label>

        <!-- Tombol -->
        <button
          type="submit"
          class="w-full py-3 text-lg font-bold text-white rounded-lg shadow-lg transition-all duration-300 bg-[#f76c5b] hover:bg-[#e65c4b] transform hover:scale-[1.01]"
        >
          Make a report
        </button>
      </form>

    </div>

    <!-- Kucing dekorasi -->
    <div class="fixed bottom-0 right-0 z-50">
      <img
        src="/images/report-rescue/sherlock-cat.png"
        alt="Kucing Sherlock"
        class="w-56 h-auto object-cover"
      />
    </div>
  </main>
</template>


<script setup>
import { ref } from 'vue';
import axios from "axios";

//untuk preview gambar saat user add laporan
const previewImages = ref([]);

const form = ref({
  photos: [],
  name: '',
  age: '',
  gender: '',
  breeds: '',
  reporterContact:'',
  lastLocation: '',
  description: '',
});

//upload dan preview photo
const handleFileUpload = (event) => {
  const files = Array.from(event.target.files);
  form.value.photos = files;
  previewImages.value = files.map(file => URL.createObjectURL(file));
};

const submitReport = async () => {
  try {
    const formData = new FormData();

    // Upload file
    form.value.photos.forEach(file => {
      formData.append("photos", file);
    });

    formData.append("cat_name", form.value.name);
    formData.append("age", form.value.age);
    formData.append("gender", form.value.gender);
    formData.append("breeds", form.value.breeds);
    formData.append("reporterContact", form.value.reporterContact);
    formData.append("location", form.value.lastLocation);
    formData.append("description", form.value.description);
    formData.append("user_id", 1);

    await axios.post("http://localhost:5000/api/reports", formData, {
      headers: { "Content-Type": "multipart/form-data" },
    });

    alert("Laporan berhasil dikirim!");

    //RESET FORM DI SINI, saat 
    form.value = {
      photos: [],
      name: '',
      age: '',
      gender: '',
      breeds: '',
      reporterContact: '',
      lastLocation: '',
      description: '',
    };

  } catch (error) {
    console.error("DETAIL ERROR:", error.response?.data || error.message);
    alert("Gagal mengirim laporan!");
  }
};

</script>
