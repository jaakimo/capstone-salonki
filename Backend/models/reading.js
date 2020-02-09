const mongoose = require('mongoose')


if ( process.env.NODE_ENV !== 'production' ) {
    require('dotenv').config()
  }


  // Do not push Password to Github !!!!!!!!
const url = 'mongodb+srv://capstonesalonki:Salasana1)@cluster0-0uoxl.mongodb.net/salonki'




mongoose.connect(url, {useNewUrlParser: true, useUnifiedTopology:true})





const readingSchema = new mongoose.Schema({
  sensor: String,    
  gx: String,
  gy: String,
  gz: String,
  ga: String,
  gb: String
  })

  
const Reading = mongoose.model('sensors', readingSchema);
  


module.exports = Reading
