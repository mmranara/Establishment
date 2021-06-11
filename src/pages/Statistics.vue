<template>
  <q-page class="row justify-center items-center">
  </q-page>
</template>

<script>
export default {
  data () {
    return {

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
  methods: {
    async fetchCovidData () {
      const res = await fetch('https://api.covid19api.com/summary')
      const data = await res.json()
      return data
    }
  },
  mounted () {
    this.renderChart(this.chartdata, this.options)
  },
  async created () {
    const data = await this.fetchCovidData()
    console.log(data)
    this.data3[0].name1 = data.Global.TotalConfirmed.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')
    this.data3[0].name2 = data.Global.TotalRecovered.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')
    this.data3[0].name3 = data.Global.TotalDeaths.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')
  }
}
</script>
