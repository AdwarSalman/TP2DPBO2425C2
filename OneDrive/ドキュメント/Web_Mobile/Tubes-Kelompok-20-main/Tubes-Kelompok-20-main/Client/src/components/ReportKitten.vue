<template>
  <section
  class="relative flex items-center justify-center bg-no-repeat bg-contain bg-center py-10 px-4 overflow-visible"
  style="background-image: url('images/vector/Background Report.png');background-color: #f7f1e8; min-height: 120vh;"
>
    <!-- Kucing kiri kanan -->
    <img
      src="/images/home/kucing_kiri_report.png"
      alt="Kucing kiri"
      class="hidden md:block absolute left-0 top-20 h-[70%] object-contain pointer-events-none"
    />
    <img
      src="/images/home/kucing_kanan_report.png"
      alt="Kucing kanan"
      class="hidden md:block absolute right-0 top-20 h-[70%] object-contain pointer-events-none "
    />

    <!-- Konten utama -->
    <div class="relative text-center flex flex-col items-center justify-center space-y-6">
      <h1 class="text-3xl sm:text-4xl lg:text-5xl font-bold text-black [text-shadow:1px_1px_2px_rgba(255,255,255,0.5)]">
        Find Missing Kitten?
      </h1>

      <img
        src="/images/home/kucing-report-button.png"
        alt="Kucing tombol"
        class="w-36 sm:w-44 lg:w-52 mx-auto absolute top-[37%]"
      />

      <div class="relative inline-flex items-center mt-30">
        <img
          src="/images/vector/Vector.svg"
          alt="Magnifying glass"
          class="absolute left-0 -ml-10 top-1/2 -translate-y-1/2 w-15 sm:w-10"
        />
        <RouterLink to="/report-rescue" class="bg-red-600 hover:bg-red-700
          text-black font-semibold
          rounded-xl!
          px-10 sm:px-12 py-3 sm:py-4 text-lg sm:text-xl flex items-center gap-2 transition-transform hover:-translate-x-0.5"
        >
          REPORT
        </RouterLink>
      </div>
    </div>
  </section>
</template>

<script setup>
// Tidak perlu JS untuk bagian ini
</script>

<style scoped></style>
