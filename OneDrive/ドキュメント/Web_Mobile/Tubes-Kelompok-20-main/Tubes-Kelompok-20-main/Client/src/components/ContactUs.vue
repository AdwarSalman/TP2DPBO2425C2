<template>
  <section class="contact-section">
    <h2>Contact Us</h2>
    <p>
      For more information about our adoption program, donations, or collaborations, 
      please contact our team through the available contact details or send us a message below.
    </p>

    <div class="contact-container">
      
      <div class="contact-card">
        <img src="/images/contactus/rumah.png" alt="rumah" class="contact-img" />
        <div class="text-content">
          <h3>Location</h3>
          <p>Street Bandung</p>
        </div>
      </div>

      <div class="contact-card">
        <img src="/images/contactus/ig.png" alt="ig" class="contact-img" />
        <div class="text-content">
          <h3>Instagram</h3>
          <p>@adoptCenter.co</p>
        </div>
      </div>

      <div class="contact-card">
        <img src="/images/contactus/wa.png" alt="wa" class="contact-img" />
        <div class="text-content">
          <h3>What’s App</h3>
          <p>+628099999999</p>
        </div>
      </div>

      <div class="contact-card">
        <img src="/images/contactus/gmail.png" alt="gmail" class="contact-img" />
        <div class="text-content">
          <h3>Email</h3>
          <p>@Adopt.center.co</p>
        </div>
      </div>

    </div>
  </section>
</template>

<script>
export default {
  name: "ContactUs"
}
</script>

<style scoped>
/* ===========
   BAGIAN 6 CONTACT US
   =========== */
.contact-section {
  background-color: #6CD4FF;
  text-align: center;
  padding: 60px 20px;
}

.contact-section h2 {
  font-size: 30px;
  font-weight: bold;
  margin-bottom: 10px;
}

.contact-section p {
  max-width: 700px;
  margin: 0 auto 40px auto;
  line-height: 1.6;
  font-size: 16px;
  color: #000;
}

.contact-container {
  display: flex;
  justify-content: center;
  flex-wrap: wrap;
  gap: 25px;
}

/* KARTU KONTAK YANG SUDAH DIUBAH */
.contact-card {
  background-color: #FFBA6B;
  border-radius: 10px;
  padding: 15px; /* Padding merata */
  box-shadow: 0 4px 4px rgba(0,0,0,0.1);
  transition: transform 0.2s, box-shadow 0.2s;
  
  /* Ini intinya */
  display: flex;
  flex-direction: row;   /* Menyamping */
  align-items: center;   /* Sejajar vertikal */
  justify-content: flex-start; /* Mulai dari kiri */
  
  width: 280px;  /* Lebar kartu */
  height: auto;  /* Tinggi otomatis */
}

.contact-card:hover {
  transform: translateY(-5px);
  box-shadow: 0 6px 10px rgba(0,0,0,0.2);
}

/* GAMBAR IKON */
.contact-img {
  width: 45px;
  height: 45px;
  object-fit: contain;
  margin-right: 15px; /* Jarak ke teks */
}

/* PEMBUNGKUS TEKS */
.text-content {
  text-align: left; /* Teks rata kiri */
}

.contact-card h3 {
  margin: 0 0 2px 0;
  font-size: 16px;
  line-height: 1.2;
}

.contact-card p {
  margin: 0;
  font-size: 12px;
  line-height: 1.2;
  max-width: none;
}
</style>