<template>
<section id="hero-area" class="relative flex flex-col-reverse lg:flex-row items-center min-h-screen overflow-hidden bg-[#f7f1e8]">
  <!-- Konten kiri -->
  <div class="w-full lg:w-1/2 flex flex-col justify-center px-6 sm:px-12 md:px-16 lg:px-24 py-12 lg:py-0 text-center lg:text-left z-10">
    <div class="header-content max-w-lg mx-auto lg:mx-0">
      <h1 class="text-3xl sm:text-4xl lg:text-5xl font-bold text-gray-800 leading-tight mb-4">
        BRING HOME THE PURRFECT FRIEND
      </h1>
      <p class="text-gray-600 text-sm sm:text-base mb-6">
        We take care of stray cats and treat them so you can adopt them safely.
      </p>
      <div class="flex flex-col sm:flex-row gap-3 sm:gap-5 justify-center lg:justify-start">
        <a href="/adoption"
           class="px-6 py-2 bg-[#ED8B3C] text-white font-semibold rounded-lg hover:bg-orange-600 transition-all shadow-md">
          Adopt
        </a>
        <a href="javascript:void(0)"
           class="text-[#ED8B3C] font-medium hover:text-orange-600">
          Join our community
        </a>
      </div>
    </div>
  </div>

  <!-- Gambar kanan -->
  <div class="w-full lg:w-1/2 flex justify-center lg:justify-end m-0 p-0">
    <img
      src="/images/home/vector.png"
      alt="Cat"
      class="hero-cat-image w-full lg:w-auto lg:h-screen object-contain lg:object-cover m-0 p-0"
    />
  </div>
</section>
  <AdoptSlider />
  <ReportKitten />
  <NewsSection />
  <FAQ />
  <AboutUs />
  <ContactUs />
</template>

<script setup>
  // 1. Import komponen slider-nya
  import AdoptSlider from '@/components/AdoptSlider.vue' 
import NewsSection from '@/components/NewsSection.vue';
import ReportKitten from '@/components/ReportKitten.vue';
import FAQ from '@/components/FAQ.vue';
import ContactUs from '@/components/ContactUs.vue';
import AboutUs from '@/components/AboutUs.vue';
  // (@ adalah shortcut untuk folder 'src')
</script>


<style scoped>
 
</style>