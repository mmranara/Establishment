<template>
    <q-page class="container">

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
      hide-bottom
    />
  </div>
</div>

    </q-page>

</template>

<script>
export default {
  data () {
    return {
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
        { name: 'date', label: 'Teacher', field: 'date', align: 'center' }
      ],
      data: [
        {
          name: 'COE 302',
          date: 'Sir. Earl',
          timein: '9:15 am',
          logout: '1:30 pm'
        },
        {
          name: 'CSM LHB',
          date: 'Sir. Uy',
          timein: '3:15 pm',
          logout: '4:00 pm'
        },
        {
          name: 'CASS 201',
          date: 'Maam Gwapa',
          timein: '6:00 pm',
          logout: '7:00 pm'
        },
        {
          name: 'CBAA 101',
          date: 'Maam Gwaps',
          timein: '7:30 pm',
          logout: '9:30 pm'
        }
      ]
    }
  }
}
</script>
