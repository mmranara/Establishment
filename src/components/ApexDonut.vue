<template>
  <apexchart type="donut" height="400" :options="chartOptions" :series="series" />
</template>

<script>
export default {
  name: 'ApexDonut',
  props: ['username', 'data'],
  data () {
    return {
      series: [2, 5, 1, 2],
      chartOptions: {
        colors: ['#42aeb8', '#053c58', '#92c9c3', '#f2716c'],
        animations: {
          enabled: true,
          easing: 'easeinout',
          speed: 1000
        },

        chart: {
          toolbar: {
            show: true
          }
        },
        title: {
          text: this.username,
          align: 'left',
          style: {
            color: ''
          }
        },
        labels: ['Youth (<18)', 'Young Adult (18 to 35)', 'Adult (36 to 55)', 'Senior (56 and up)'],
        responsive: [{
          breakpoint: 480,
          options: {
            chart: {
              width: 250
            },
            legend: {
              position: 'bottom'
            }
          }
        }],
        legend: {
          labels: {
            colors: ''
          }
        }
      }
    }
  }
}
</script>
