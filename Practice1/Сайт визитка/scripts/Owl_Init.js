$(document).ready(function()
{
  $('.owl-carousel').owlCarousel(
    {
      items : 2,
      loop: true,
      autoplay: true,
      smartSpeed: 1000,
      autoplayTimeout: 3500,
      // nav:true,
      dots: true,
      responsiveClass:true,
      responsive:{
        0:{
            items:1,
            nav:false,
            loop: true
        },
        600:{
            items:2,
            nav:false,
            loop: true
        },
        1000:{
            items:2,
            nav:false,
            loop: true
        }
    }
    }
  );
});
