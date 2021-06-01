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
            v-model="formData.room_no"
            label="Input Room Number *"
          />

        <div class="row">
        <div class="q-pa-xs">
        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.time_in"
            label="Time In *"
          /></div>
        <div class="q-pa-xs">
        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.time_out"
            label="Time Out *"
          /></div>
        </div>

        <q-input
            bg-color="grey-4"
            filled
            v-model="formData.teacher"
            label="Teacher *"
          />

        <p class="text-subtitle1" v-if="result"><b>{{ result }}</b></p>

<div class="q-pa-xs">
        <q-btn  style="width:100px;height:40px;" color="teal-10" unelevated size="md" label="Update" @click="addRoom()"/>
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
import { firebaseDb } from 'src/boot/firebase'
export default {
  name: 'SignupPage.vue',
  data () {
    return {
      result: null,
      step: 1,
      formData: {
        room_no: '',
        time_in: '',
        time_out: '',
        teacher: ''
      }
    }
  },
  methods: {
    addRoom () {
      firebaseDb.ref('rooms').push({
        room_num: this.formData.room_no,
        time_in: this.formData.time_in,
        time_out: this.formData.time_out,
        teacher: this.formData.teacher
      })
      this.formData.room_no = ''
      this.formData.time_in = ''
      this.formData.time_out = ''
      this.formData.teacher = ''
      this.result = 'New Room Added'
    }
  }
}
</script>

<style>
</style>
