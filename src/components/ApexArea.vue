<template>
  <apexchart type="area" height="400" :options="chartOptions" :series="series"></apexchart>
</template>

<script>
import { mapState } from 'vuex'
export default {
  name: 'ApexArea',
  props: ['username', 'dataA'],
  data () {
    return {
      series: [{
        name: 'Customers',
        data: this.dataA
      }],
      chartOptions: {
        animations: {
          enabled: true,
          easing: 'easeinout',
          speed: 1000
        },
        dataLabels: {
          enabled: false
        },
        title: {
          text: this.username,
          align: 'left',
          style: {
            color: ''
          }
        },
        xaxis: {
          categories: ['8:00 AM', '9:00 AM', '10:00 AM', '11:00 AM', '12:00 PM', '1:00 PM', '2:00 PM', '3:00 PM', '4:00 PM', '5:00 PM', '6:00 PM', '7:00 PM'],
          labels: {
            style: {
              colors: ''
            }
          }
        },
        yaxis: {
          labels: {
            style: {
              colors: ''
            }
          }
        }
      }
    }
  },
  computed: {
    ...mapState('store', ['userDetails'])
  }
}
</script>

<style>
</style>
