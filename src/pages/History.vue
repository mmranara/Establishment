<template>
    <q-page class="container">

     <div v-if="!showCamera">
     <div>
        <div class="q-pa-xs">
            <q-img src="~assets/z.png" />
        </div>
        <q-separator dark inset /><q-separator dark inset /><q-separator dark inset /><q-separator dark inset /><q-separator dark inset /><q-separator dark inset />
     </div>

  <q-footer >
      <q-tabs class="bg-teal-10" style="height:50px;">
        <q-route-tab to="/school" label="School Input" style="width:100%;height:60px;"/>
        <q-route-tab to="/history" label="History"  style="width:100%;height:60px;"/>
      </q-tabs>
  </q-footer>

<div>
  <div class="q-pa-xs">
    <q-table
      :data="data"
      :columns="columns"
      row-key="name"
    >
    <template v-slot:body="props">
        <q-tr :props="props">
          <q-td
            v-for="(col) in props.cols"
            :key="col.name"
            :props="props"
          >
            {{ col.value }}
          </q-td>
          <q-td>
            <q-btn color = "teal" icon = "camera_alt" @click="qrRoom(props.row), turnCameraOn()">
              QR Scan
            </q-btn>
          </q-td>
        </q-tr>
      </template>
    </q-table>
  </div>
</div>
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
              <q-item-section>{{ 'Age: ' + result[1] }}</q-item-section>
            </q-item>

            <q-item>
              <q-item-section>{{ 'Address: ' + result[2] }}</q-item-section>
            </q-item>

            <q-item>
              <q-item-section>{{ 'Contact Number: ' + result[3] }}</q-item-section>
            </q-item>

          </q-list>
        </q-card-section>

        <q-card-actions align="right" class="bg-white text-teal">
          <q-btn flat label="OK" v-close-popup />
        </q-card-actions>
      </q-card>
  </q-dialog>
</div>

  <div v-if="showCamera">
    <qrcode-stream :camera="camera" @decode="onDecode">
    </qrcode-stream>
  </div>
  </q-page>
</template>

<script>
import { firebaseDb } from 'src/boot/firebase'
import { QrcodeStream } from 'vue-qrcode-reader'
export default {
  name: 'PageIndex',
  components: { QrcodeStream },
  data () {
    return {
      small: false,
      isValid: undefined,
      camera: 'auto',
      result: {},
      showCamera: false,
      search: '',
      columns: [
        {
          name: 'name',
          required: true,
          label: 'Room',
          align: 'left',
          field: row => row.name,
          format: name => `${name}`
        },
        { name: 'timein', label: 'Time In', field: 'timein' },
        { name: 'logout', label: 'Time Out', field: 'logout' },
        { name: 'date', label: 'Teacher', field: 'date', align: 'center' },
        { label: '', align: 'left' }
      ],

      keys: [{ id: '' }],

      chosenEST: '',

      data: [
        // {
        //   name: 'COE 302',
        //   date: 'Sir. Earl',
        //   timein: '9:15 am',
        //   logout: '1:30 pm'
        // },
        // {
        //   name: 'CSM LHB',
        //   date: 'Sir. Uy',
        //   timein: '3:15 pm',
        //   logout: '4:00 pm'
        // },
        // {
        //   name: 'CASS 201',
        //   date: 'Maam Gwapa',
        //   timein: '6:00 pm',
        //   logout: '7:00 pm'
        // },
        // {
        //   name: 'CBAA 101',
        //   date: 'Maam Gwaps',
        //   timein: '7:30 pm',
        //   logout: '9:30 pm'
        // },
        // {
        //   name: 'aasf asf',
        //   date: 'asf sfa',
        //   timein: '7:3fa0asf pasdm',
        //   logout: '9:30 asfpm'
        // }
      ]
    }
  },
  computed: {
    textInfo () {
      return this.showCamera ? 'position the qrcode on the camera' : 'Press the button and scan a qrcode.'
    }
  },
  methods: {
    qrRoom (key) {
      this.chosenEST = this.data[this.data.indexOf(key)].id
    },

    async onDecode (content) {
      content = content.split('|')
      firebaseDb.ref('rooms/' + this.chosenEST + '/students').push({
        date: Date.now(),
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
  },
  mounted () {
    this.chosenEST = ''
    var rooms = []
    var keys = []
    var roomsRef = firebaseDb.ref('rooms')
    roomsRef.once('value', function (snapshot) {
      snapshot.forEach(function (childSnapshot) {
        var room = childSnapshot.val()
        rooms.push({ name: room.room_num, date: room.teacher, timein: room.time_in, logout: room.time_out, id: childSnapshot.key })
        keys.push({ id: childSnapshot.key })
      })
    })
    this.keys = keys
    this.data = rooms
  }
}

</script>
