<template>
<q-page class="bg-teal window-height:100% row justify-center items center ">
  <q-img src="~assets/lolz.jpg" class="menu-image fixed-center" />

 <div class="column q-pa-md">
      <div class="row">
        <q-card square class="shadow-24" style="width:415px;height:470px;">

              <div class="q-pa-xs">
        <q-img src="~assets/z.png"/></div>

          <q-card-section>
              <q-form
                  @submit="onSubmit"
                  class="q-gutter-md">

          <q-input
            bg-color="grey-4"
            filled
            v-model="formData.name"
            label="Input Room Number *"
          />

        <div class="row">
        <div class="q-pa-xs">
        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.name"
            label="Time In *"
          /></div>
        <div class="q-pa-xs">
        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.name"
            label="Time Out *"
          /></div>
        </div>

        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.name"
            label="Teacher *"
          />

<div class="q-pa-xs">
        <q-btn  style="width:100px;height:40px;" color="teal-10" unelevated size="md" label="Update" />
</div>
          </q-form>
         </q-card-section>
       </q-card>
      </div>
    </div>

  <q-footer >
      <q-tabs class="bg-teal-10" style="height:50px;">
        <q-route-tab to="/school" label="School Input" style="width:100%;height:60px;"/>
        <q-route-tab to="/history" label="History"  style="width:100%;height:60px;"/>
      </q-tabs>

  </q-footer>
</q-page>
</template>

<script>

export default {
  name: 'SignupPage.vue',
  data () {
    return {
      step: 1,
      formData: {
        name: ''
      }
    }
  }
}
</script>

<style>
</style>
