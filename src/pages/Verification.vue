<template>
<q-page class="constrain-more  window-height:100% row justify-center items-center ">

    <q-stepper
    style="width:100%;height:55px"
      v-model="step"
      ref="stepper"
      alternative-labels
      color="primary"
      animated
    >
      <q-step
        :name="1"
        icon="settings"
        :done="step > 1">
      </q-step>

      <q-step
        :name="2"
        icon="party_mode"
        :done="step > 2">
      </q-step>

      <q-step
        :name="3"
        icon="local_post_office">
      </q-step>
    </q-stepper>

    <div class="q-pa-xl text-center text-blue-grey-10">
      <div class="q-pa-md">
        <span class="text-h6">
          Enter Semi-Verification Code
        </span>
      </div>
      <div class="q-pa-sm">
        <span class="text-h6">
           <q-input
             rounded
             outlined
             style="width:300px"
             v-model="id"
             mask="               #       #       #       #       #       # "
             fill-mask
          />
        </span>
      </div>
    </div>

    <div class="q-pa-xs text-center text-blue-grey-10">
       <span class="text-subtitle2">
        Your semi-verification code is sent by SMS/Email
       </span>
    </div>

    <div class="q-pa-lg flex flex-center">
     <div>
      <q-btn to='/index' style=" width:200px;height:40px;"  type="submit" unelevated size="md" color="teal-10" class="text-white" label="Register" />
     </div>
    </div>

      <q-footer class="bg-teal-10">
    <q-toolbar>
      <q-img src="~assets/lol.png" class="header-image absolute-bottom" />
    </q-toolbar>
  </q-footer>

 </q-page>
</template>

<script>
export default {
  name: 'Verification.vue',
  data () {
    return {
      step: 3,
      id: null
    }
  }
}
</script>

<style lang="sass">
.header-image
  height: 100%
  opacity: 0.2
  z-index: -1
  filter: grayscale(100%)

</style>
