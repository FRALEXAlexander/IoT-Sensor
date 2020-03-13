<template>
  <div id="app">
   <BME280Sensor/>
   <GY1145Sensor/>
  </div>
</template>

<script>

import BME280Sensor from './components/BME280Sensor.vue'
import GY1145Sensor from './components/GY1145Sensor.vue'


export default {
  name: 'App',
  components: {
    BME280Sensor,
    GY1145Sensor
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
 margin: auto;
}
</style>
