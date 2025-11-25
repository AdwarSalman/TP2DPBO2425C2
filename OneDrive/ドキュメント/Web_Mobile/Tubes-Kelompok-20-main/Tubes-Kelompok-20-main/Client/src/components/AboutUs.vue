<template>
  <!-- HERO SECTION -->
  <section id="about" class="about-hero">
    <div class="hero-text">
      <h1 class >About <span>Adopt Center</span></h1>
      <p>We’re a community of animal lovers dedicated to helping stray cats find safe and loving homes.</p>
    </div>
  </section>

  <!-- MISSION AND VISION -->
  <section class="mission-vision">
    <div class="mv-card">
      <span class="icon">🐾</span>
      <h3>Our Mission</h3>
      <p>To rescue, rehabilitate, and rehome stray cats through love and collaboration.</p>
    </div>
    <div class="mv-card">
      <span class="icon">💙</span>
      <h3>Our Vision</h3>
      <p>A world where every cat has a loving and safe place to call home.</p>
    </div>
  </section>

  <!-- OUR STORY -->
   <div class="story-container">

     <section class="story">
       <div class="story-text">
         <h2>Our Story</h2>
         <p>Adopt Center was founded by a group of volunteers who were concerned about the increasing number of stray cats in their neighborhood. We decided to build a platform to connect rescuers, adopters, and donors in one caring community.</p>
        </div>
        <!-- <img src="images/about/doker-kucing.png" class="story-img"> -->
      </section>
    </div>

  <!-- VALUES -->
  <section class="values">
    <div class="value-card">
      <span class="icon">🐾</span>
      <h4>Rescue</h4>
      <p>We help save cats from unsafe environments.</p>
    </div>
    <div class="value-card">
      <span class="icon">➕</span>
      <h4>Medical Care</h4>
      <p>Provide health check and vaccination.</p>
    </div>
    <div class="value-card">
      <span class="icon">🏠</span>
      <h4>Foster & Adopt</h4>
      <p>Connect cats with loving adopters.</p>
    </div>
    <div class="value-card">
      <span class="icon">📢</span>
      <h4>Awareness</h4>
      <p>Educate the community to care for stray cats.</p>
    </div>
  </section>
</template>


<style scoped>
body {
  margin: 0;
  font-family: "Poppins", sans-serif;
  background: #f7f1e8;
  color: #333;
}

/* HERO */
.about-hero {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 10px 10%;
  background: #f7f1e8;
}

.hero-text h1 {
  font-size: 48px;  
  font-weight: bold;
  margin-bottom: 10px; 
}

.hero-text p {
  font-size: 18px;
  color: #555;      
}

.hero-text h1 span { color: #ED8B3C; }

.hero-cat {
  width: 260px;
  border-radius: 20px;
  box-shadow: 0 8px 20px rgba(0, 0, 0, 0.15);
}

/* MISSION & VISION */
.mission-vision {
  display: flex;
  gap: 20px;
  padding: 60px 10%;
  justify-content: center;
  background-color: #f7f1e8;
  
}

.mv-card {
  background: white;
  padding: 25px;
  border-radius: 20px;
  flex: 1;
  text-align: center;
  box-shadow: 0 8px 20px rgba(0, 0, 0, 0.1);
}

/* STORY */
.story-container {
  background: #f7f1e8;
  padding: 40px 0;
}
.story {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 60px 10%;
  background-color: white;
  border-radius: 20px;
  margin: 40px 10%;
  box-shadow: 0 8px 20px rgba(0,0,0,0.1);
}
.story-img {
  width: 300px;
  border-radius: 12px;
  margin-left: 30px;
}

/* VALUES */
.values {
  display: flex;
  justify-content: space-between;
  padding: 60px 10%;
  background: #f7f1e8;
}

.value-card {
  text-align: center;
  width: 22%;
  background: white;
  padding: 25px;
  border-radius: 20px;
  box-shadow: 0 8px 20px rgba(0,0,0,0.1);
}
</style>