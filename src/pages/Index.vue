<template>
  <q-page>
    <div class="row">
      <div
        v-if="!showCamera"
        class="col-12 text-center q-pt-md"
      >
        <div>
          <div class="q-pa-xs">
            <q-img src="~assets/z.png"/>
          </div>
         </div>
      </div>
    </div>

    <div class="row justify-center q-pt-lg">
       <div class="col-12 text-center">
        <span class="text-subtitle2 text-grey-9">
          {{ textInfo }}
        </span>
        <q-btn color="teal-10" rounded icon="camera_alt" label="Read QRCode"
          class="full-width" size=" lg" @click="turnCameraOn()"
          v-show="!showCamera"/>
          <div v-if="showCamera">
            <qrcode-stream :camera="camera" @decode="onDecode">
            </qrcode-stream>
          </div>
      </div>
    </div>
      <div>
        <q-dialog
          v-model="small"
        >
          <q-card style="width: 300px">
            <q-card-section class="justify-center">
              <div class="text-h6">Added</div>
            </q-card-section>

            <q-card-section class="q-pt-none">
                <q-list>
                  <q-item>
                    <q-item-section>{{ 'Name: ' + result[0] }}</q-item-section>
                  </q-item>

                  <q-item>
                    <q-item-section>{{ 'Covid Status: ' + result[4] }}</q-item-section>
                  </q-item>

                </q-list>
              </q-card-section>

              <q-card-actions align="right" class="bg-white text-teal">
                <q-btn flat label="OK" v-close-popup />
              </q-card-actions>
            </q-card>
        </q-dialog>
      </div>
  </q-page>
</template>
<style>
</style>

<script>
import { firebaseDb } from 'src/boot/firebase'
import { QrcodeStream } from 'vue-qrcode-reader'
export default {
  name: 'PageIndex',
  components: {
    QrcodeStream
  },
  data () {
    return {
      small: false,
      isValid: undefined,
      camera: 'auto',
      result: {},
      showCamera: false
    }
  },
  computed: {
    textInfo () {
      return this.showCamera ? 'position the qrcode on the camera' : 'Press the button and scan a qrcode.'
    }
  },
  methods: {
    async onDecode (content) {
      content = content.split('|')
      firebaseDb.ref('customers').push({
        date: Date.now(),
        status: content[4],
        contact: content[3],
        address: content[2],
        age: content[1],
        name: content[0]
      })
      this.result = content
      this.small = true
      this.turnCameraOff()
    },

    turnCameraOn () {
      this.camera = 'auto'
      this.showCamera = true
    },

    turnCameraOff () {
      this.camera = 'off'
      this.showCamera = false
    }
  }

}
</script>

<style scoped>
.validation-success,
.validation-failure,
.validation-pending {
  position: absolute;
  width: 100%;
  height: 100%;

  background-color: rgba(255, 255, 255, .8);
  text-align: center;
  font-weight: bold;
  font-size: 1.4rem;
  padding: 10px;

  display: flex;
  flex-flow: column nowrap;
  justify-content: center;
}
.validation-success {
  color: green;
}
.validation-failure {
  color: red;
}
</style>
