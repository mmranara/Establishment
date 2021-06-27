<template>
  <q-page class="row justify-center items-center">

    <q-card class="fit">

      <div
        class="row q-col-gutter-md q-px-md q-py-md"
        key="allCharts"
      >
        <q-card v-if="userDetails.type === 'School'" class="q-ma-md q-pa-xl fit">
            <div class="col-md-6 col-sm-12 col-xs-12">
                <apex-donut-school :key="componentKey"></apex-donut-school>
            </div>
        </q-card>

        <q-card v-else class="q-ma-md q-pa-xl fit">
            <apex-donut :username="userDetails.name" :data="this.estDataD" :key="componentKey"></apex-donut>
        </q-card>

        <q-card v-if="userDetails.type === 'School'" class="q-ma-md q-pa-xl fit">
          <div class="col-md-6 col-sm-12 col-xs-12">
              <apex-area-school :key="componentKey"></apex-area-school>
          </div>
        </q-card>

        <q-card v-else class="q-ma-md q-pa-xl fit">
          <div class="col-md-6 col-sm-12 col-xs-12">
              <apex-area :username="userDetails.name" :dataA="this.estDataA" :key="componentKey" ></apex-area>
          </div>
        </q-card>
      </div>
    </q-card>
  </q-page>
</template>

<script>
import { firebaseAuth, firebaseDb } from 'boot/firebase'
import { mapState } from 'vuex'
export default {
  components: {
    ApexAreaSchool: () => import('components/ApexAreaSchool'),
    ApexDonutSchool: () => import('components/ApexDonutSchool'),
    ApexArea: () => import('components/ApexArea'),
    ApexDonut: () => import('components/ApexDonut')
  },
  data () {
    return {
      componentKey: 0,
      id: firebaseAuth.currentUser.uid,
      estDataA: [],
      estDataD: [],
      loading: false,
      options: {},
      series: [44, 55, 41, 17, 15],
      columns1: [
        { field: 'name1', label: 'Confirmed', align: 'center', headerClasses: 'text-red-10' },
        { align: 'center', label: 'Recovered', field: 'name2', headerClasses: 'text-green' },
        { align: 'center', label: 'Deaths', field: 'name3' }
      ],
      columns2: [
        { field: 'name1', label: 'Confirmed', align: 'center', headerClasses: 'text-red-10' },
        { align: 'center', label: 'Recovered', field: 'name2', headerClasses: 'text-green' },
        { align: 'center', label: 'Deaths', field: 'name3' }
      ],
      columns3: [
        { field: 'name1', label: 'Confirmed', align: 'center', headerClasses: 'text-red-10' },
        { align: 'center', label: 'Recovered', field: 'name2', headerClasses: 'text-green' },
        { align: 'center', label: 'Deaths', field: 'name3' }
      ],
      data1: [
        {
          name1: '19,093',
          name2: '16,578',
          name3: '350'
        }
      ],
      data2: [
        {
          name1: '1,193,976',
          name2: '1,131,942',
          name3: '20,169'
        }
      ],
      data3: [
        {
          name1: '',
          name2: '',
          name3: '3,488,242'
        }
      ]
    }
  },
  computed: {
    ...mapState('store', ['userDetails'])
  },
  created () {
    this.fetchData()
  },
  watch: {
    // call again the method if the route changes
    '$route': 'fetchData'
  },
  methods: {
    forceRerender () {
      this.componentKey += 1
    },
    fetchData () {
      this.estDataA = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
      let categories = ['8:00 AM', '9:00 AM', '10:00 AM', '11:00 AM', '12:00 PM', '1:00 PM', '2:00 PM', '3:00 PM', '4:00 PM', '5:00 PM', '6:00 PM', '7:00 PM']
      var refA = firebaseDb.ref('users/' + this.id + '/customers')
      refA.on('value', snapshot => {
        snapshot.forEach(childSnapshot => {
          for (let i = 0; i < categories.length; i++) {
            if ((new Intl.DateTimeFormat('en', { hour: 'numeric' }).format(childSnapshot.val().date))[0] === categories[i][0]) {
              this.estDataA[i] += 1
            }
          }
        })
      })
      this.estDataD = [0, 0, 0, 0]
      var refE = firebaseDb.ref('users/' + this.id + '/customers')
      refE.on('value', snapshot => {
        snapshot.forEach(childSnapshot => {
          var room = childSnapshot.val()
          if (room.age < 18) {
            this.estDataD[0] += 1
          } else if (room.age >= 18 && room.age <= 35) {
            this.estDataD[1] += 1
          }
          if (room.age >= 36 && room.age <= 55) {
            this.estDataD[2] += 1
          }
          if (room.age >= 56) {
            this.estDataD[3] += 1
          }
        })
      })
      this.forceRerender()
    }
  }
}
</script>
