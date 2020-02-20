const mongoose = require('mongoose')


if ( process.env.NODE_ENV !== 'production' ) {
    require('dotenv').config()
  }


  // Do not push Password to Github !!!!!!!!
const url = 'mongodb+srv://readonly:Salasana1%29@cluster0-0uoxl.mongodb.net/salonki_test'




mongoose.connect(url, {useNewUrlParser: true, useUnifiedTopology:true})





const readingSchema = new mongoose.Schema({
  sensor: String,    
  gx: String,
  gy: String,
  gz: String,
  ga: String,
  gb: String,
  lat: String,
  lng: String
  })

  
const Reading = mongoose.model('sensors', readingSchema);
  


module.exports = Reading
