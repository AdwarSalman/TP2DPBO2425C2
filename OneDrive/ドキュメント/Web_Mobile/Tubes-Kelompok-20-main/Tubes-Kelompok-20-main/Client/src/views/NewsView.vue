<template>
  <section id="news" class="py-16 bg-gray-50 mt-5">
    <div class="container mx-auto px-4 lg:px-8">
      <div class="text-center mb-10">
        <h1 class="text-2xl sm:text-3xl lg:text-4xl font-bold text-gray-800 tracking-tight">
          News About Us
        </h1>
        <p class="text-gray-500 mt-2 text-sm sm:text-base">
          Get the latest stories from our cat community
        </p>
      </div>

      <!-- Daftar berita -->
      <div class="space-y-8">
        <div
          v-for="(news, index) in newsList"
          :key="index"
          class="bg-white rounded-2xl shadow-md hover:shadow-lg transition-all overflow-hidden border border-gray-100 cursor-pointer"
          @click="openPopup(news)"
        >
          <div class="flex flex-col md:flex-row">
            <div class="md:w-[40%] relative">
              <img
                :src="news.image"
                alt="News image"
                class="w-[60%] h-56 md:h-full object-cover"
              />
            </div>
            <div class="md:w-[60%] flex flex-col p-6 justify-start">
              <h2 class="font-semibold text-gray-800 text-lg sm:text-xl lg:text-2xl mb-2">
                {{ news.title }}
              </h2>
              <p class="text-gray-600 text-sm sm:text-base lg:text-lg leading-relaxed">
                {{ news.desc }}
              </p>
            </div>
          </div>

          <!-- Aksi -->
          <div class="flex flex-wrap items-center justify-between px-6 py-3 border-t border-gray-100 bg-gray-50" @click.stop>
            <div class="flex items-center gap-3 text-gray-600 text-sm sm:text-base">
              <button @click.stop="toggleLike(index)" class="flex items-center gap-1 px-2 py-1 rounded-md hover:bg-gray-200">
                ❤️ <span>{{ news.likes }}</span>
              </button>

              <button @click.stop="openPopup(news)" class="flex items-center gap-1 px-2 py-1 rounded-md hover:bg-gray-200">
                💬 <span>{{ news.comments.length }}</span>
              </button>

              <button @click.stop="shareNews(news)" class="flex items-center gap-1 px-2 py-1 rounded-md hover:bg-gray-200">
                🔗
              </button>
            </div>

            <div class="flex gap-2 text-lg sm:text-xl md:text-2xl lg:text-2xl text-gray-700" @click.stop>
              <span
                v-for="emoji in emojis"
                :key="emoji.char"
                class="hover:scale-110 transition-transform cursor-pointer flex items-center gap-1"
                @click.stop="addReaction(index, emoji.char)"
              >
                {{ emoji.char }}
                <small v-if="news.reactions[emoji.char]">{{ news.reactions[emoji.char] }}</small>
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- Reusable Popup -->
    <NewsModal
      v-if="selectedNews"
      :visible="!!selectedNews"
      :news="selectedNews"
      @close="selectedNews = null"
      @update-news="handleUpdateNews"
    />
  </section>
</template>
<script setup>
import { ref, onMounted } from "vue"
import NewsModal from "../components/NewsPopUp.vue"
import { NewsApi } from "../api/newsApi.js"

const newsList = ref([])

const emojis = [{ char: "😺" }, { char: "😻" }, { char: "😹" }]
const selectedNews = ref(null)

const fetchNews = async () => {
  try {
    // 1. Ambil semua berita
    const res = await NewsApi.getNews()
    const allNews = res.data    // pakai ini terus

    console.log("Berita diterima:", allNews)

    // 2. Ambil semua komentar setiap berita
    const commentPromises = allNews.map(n =>
      NewsApi.getComments(n.id).catch(() => ({ data: [] }))
    )

    const commentsResults = await Promise.all(commentPromises)

    // 3. Format berita agar cocok dengan template
    const BASE = import.meta.env.VITE_STATIC_BASE_URL.replace(/\/$/, "")

    newsList.value = allNews.map((n, idx) => ({
      ...n,
      desc: n.desc || n.content || "",
      image: BASE + (n.image || "/images/placeholder.jpg"),
      likes: n.likes ?? 0,
      isLiked: false,
      comments: Array.isArray(commentsResults[idx]?.data)
        ? commentsResults[idx].data
        : [],
      reactions: n.reactions || {},
      newComment: ""
    }))

  } catch (err) {
    console.error("Gagal fetch news:", err)
  }
}

onMounted(fetchNews)


// --- fitur UI sama seperti NewsView lama ---

const toggleLike = (index) => {
  const news = newsList.value[index]
  news.isLiked = !news.isLiked
  news.likes += news.isLiked ? 1 : -1
}

const shareNews = (news) => {
  navigator.clipboard.writeText(`https://catnews.com/article/${encodeURIComponent(news.title)}`)
  alert("Link berita disalin ke clipboard!")
}

const addReaction = (index, emoji) => {
  const reactions = newsList.value[index].reactions
  reactions[emoji] = (reactions[emoji] || 0) + 1
}

const openPopup = (news) => {
  selectedNews.value = JSON.parse(JSON.stringify(news))
}

const handleUpdateNews = (updated) => {
  console.log("Updated news:", updated)
}
</script>
