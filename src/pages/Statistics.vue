<template>
  <q-page class="row justify-center items-center">

    <q-card class="">

      <div class="text-h5 q-ma-md row justify-center items-center">{{ userDetails.name }}</div>

      <div
        class="row q-col-gutter-md q-px-md q-py-md"
        key="allCharts"
      >
        <q-card class="q-ma-md q-pa-xl">
          <div class="col-md-6 col-sm-12 col-xs-12">
              <apex-donut :options="options" :series="series"></apex-donut>
          </div>
        </q-card>

        <q-card class="q-ma-md q-pa-xl">
          <div class="col-md-6 col-sm-12 col-xs-12">
              <apex-area></apex-area>
          </div>
        </q-card>
      </div>
    </q-card>
  </q-page>
</template>

<script>
import CardBase from 'components/CardBase'
import { mapState, mapActions } from 'vuex'
export default {
  components: {
    ApexArea: () => import('components/ApexArea'),
    ApexDonut: () => import('components/ApexDonut')
  },
  data () {
    return {
      options: {},
      series: [44, 55, 41, 17, 15],
      loading: true,
      dialog: true,
      colors: [
        'linear-gradient( 135deg, #ABDCFF 10%, #0396FF 100%)',
        'linear-gradient( 135deg, #2AFADF 10%, #4C83FF 100%)',
        'linear-gradient( 135deg, #FFD3A5 10%, #FD6585 100%)',
        'linear-gradient( 135deg, #EE9AE5 10%, #5961F9 100%)'
      ],
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
  methods: {

  },
  mounted () {
    this.renderChart(this.chartdata, this.options)
  },
  created () {
    this.$q.loading.show({
      backgroundColor: 'purple-10',
      delay: 0
    })
    setTimeout(() => {
      this.$q.loading.hide()
    }, 1300)
  }
}
</script>
