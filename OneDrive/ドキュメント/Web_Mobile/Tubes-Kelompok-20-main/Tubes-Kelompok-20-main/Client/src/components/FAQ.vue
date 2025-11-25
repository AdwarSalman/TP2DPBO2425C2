<template>
   <section id="faq" class="faq-section">
     <div class="faq-container">
      <h2>Frequently Asked Questions</h2>

       <div class="faq-item">
      <details>
        <summary>What are the requirements to adopt a cat?</summary>
        <p>You need to fill out the adoption form, provide ID, and agree to the adoption policy.</p>
      </details>
    </div>

      <div class="faq-item">
      <details>
        <summary>What documents or information need to be prepared for adoption?</summary>
        <p>Prepare your ID card, proof of residence, and any references if required.</p>
      </details>
    </div>

      <div class="faq-item">
      <details>
        <summary>Is there a fee to adopt a cat?</summary>
        <p>Some shelters may ask for a small adoption fee to cover medical costs.</p>
      </details>
    </div>

     <div class="faq-item">
      <details>
        <summary>Do you have any questions?</summary>
        <p>You can contact us anytime via email or our social media accounts.</p>
      </details>
    </div>
  </div>
</section>
</template>

<style scoped>

/*===========
  BAGIAN 5 FAQ
  ===========*/
.faq-section {
  background-color: #f7f1e8; /*latar warna putih*/
  padding: 60px 75px; /* kasih jarak atas dan bawah */
}

/* Tambahkan kotak latar biru di dalam section */
.faq-container {
  background-color: white;
  padding: 40px 20px;
  border-radius: 20px;
  max-width: 2000px; /* biar gak terlalu lebar */
  margin: 0 auto; /* biar posisi di tengah */
  box-shadow: 0 4px 8px rgba(0,0,0,0.1);
}

.faq-section h2 {
  display: inline-block;
  text-shadow: #000000 0px 1px 1px;
  padding: 10px 20px;
  border-radius: 15px;
  margin-bottom: 30px; /*supaya antara judul dan pertanyaan ada jarak*/
  font-weight: bold;
  font-size: 25px;
}

.faq-item {
  background-color: #FFBA6B;
  border-radius: 5px;
  padding: 10px;
  margin-bottom: 20px;
  box-shadow: 0 4px 4px rgba(0,0,0,0.05);
}

</style>

<script setup>

</script>
