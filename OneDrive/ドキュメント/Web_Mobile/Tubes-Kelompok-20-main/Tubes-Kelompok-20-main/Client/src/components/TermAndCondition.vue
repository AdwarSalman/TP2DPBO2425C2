<template>
  <section class="min-h-screen bg-gradient-to-b from-gray-50 to-white py-20 px-6">
    <div class="max-w-4xl mx-auto">
      <div class="text-center mb-12">
        <h3 class="text-4xl font-extrabold text-gray-900 mb-4">
          Terms and Conditions
        </h3>
        <p class="text-gray-600 text-base max-w-2xl mx-auto">
          Please read and understand the following terms and conditions before proceeding with the adoption process.
        </p>
        <div class="w-60 h-[2px] bg-gray-300 mx-auto mt-6"></div>
      </div>

      <div class="bg-white shadow-lg shadow-gray-100/60 rounded-2xl p-10 border border-gray-100">
        <ol class="list-decimal pl-6 space-y-5 text-gray-700 leading-relaxed text-base">
          <li>Must be at least <strong>18 years old</strong> or have permission from a parent/guardian.</li>
          <li>Willing to provide valid identification (<strong> KTP /Family Card</strong>).</li>
          <li>Residing in an environment/housing that permits keeping pets.</li>
          <li>Willing to care for the cat with love and responsibility.</li>
          <li>Must provide nutritious food, clean water, and a safe environment.</li>
          <li>Must allocate time to play and interact with the cat.</li>
          <li>The cat should not be continuously confined in a cage.</li>
          <li>Adopters are prohibited from reselling or trading the adopted cat.</li>
          <li>Must not use the cat for dangerous experiments or competitions.</li>
          <li>Adopters are prohibited from abandoning, harming, or releasing the cat without permission.</li>
          <li>The adopter agrees to be visited or inspected by the adoption party at any time.</li>
          <li>If the adopter is no longer able to care for the cat, they must return it.</li>
          <li>
            By signing this adoption agreement, the prospective adopter agrees and is willing
            to comply with all the above conditions.
          </li>
        </ol>

        <div class="border-t border-gray-200 mt-10 pt-6 text-sm text-gray-500 text-center">
          <p>
            Thank you for your commitment to providing a loving new home.
          </p>
        </div>
      </div>

      <button
        @click="goToAdoptForm"
        class="mt-8 w-full bg-gray-900 text-white py-3 rounded-lg font-semibold hover:bg-gray-700 transition-colors"
      >
        Agree and Proceed to Adoption Form
      </button>
    </div>
  </section>
</template>

<script setup>
import { useRouter } from "vue-router";
const router = useRouter();

const goToAdoptForm = () => {
  // Assuming the route for the adoption form is '/adopt-now'
  router.push("/adopt-now");
};
</script>