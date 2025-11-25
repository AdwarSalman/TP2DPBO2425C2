// /src/api/newsApi.js
import axios from 'axios'
export const NewsApi = {
  async getNews() {
    try {
      const res = await axios.get('/news')
      return res && res.data ? res : { data: [] }
    } catch (err) {
      console.error('getNews error', err)
      return { data: [] }
    }
  },

  async getComments(newsId) {
    try {
      const res = await axios.get(`/news/${newsId}/comments`)
      return res && res.data ? res : { data: [] }
    } catch (err) {
      console.warn(`getComments error for ${newsId}`, err)
      return { data: [] }
    }
  },

  async addComment(newsId, payload) {
    try {
      return await axios.post(`/news/${newsId}/comments`, payload)
    } catch (err) {
      console.error('addComment error', err)
      return {
        data: {
          id: Date.now(),
          news_id: newsId,
          comment: payload.comment ?? payload.text,
          user_id: payload.user_id ?? null
        }
      }
    }
  },

  // LIKE COMMENT
  likeComment(newsId, commentId) {
    return axios.post(`/news/${newsId}/comments/${commentId}/like`)
  },

  // UNLIKE COMMENT
  unlikeComment(newsId, commentId) {
    return axios.post(`/news/${newsId}/comments/${commentId}/unlike`)
  },

  // DELETE COMMENT
  deleteComment(newsId, commentId) {
    return axios.delete(`/news/${newsId}/comments/${commentId}`)
  }
}
