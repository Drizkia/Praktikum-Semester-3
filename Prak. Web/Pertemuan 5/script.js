// Data testimonial
const testimonials = [
    {
        text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quid quis volutpat ullamcorper quis duis nam massa adipiscing et commodo hendrerit. Accumsan quam quisque quam egestas sit archifento hendrerit.",
        name: "Mbahoon",
        role: "Photographer",
        rating: 5,
        avatar: "Minion.webp"
    },
    {
        text: "Amazing service! The team was very professional and delivered exactly what we needed. Highly recommended for anyone looking for quality work.",
        name: "Sarah Johnson",
        role: "Designer",
        rating: 5,
        avatar: "😃"
    },
    {
        text: "Great experience working with them. Very responsive and attentive to details. Will definitely use their services again in the future!",
        name: "John Doe",
        role: "Developer",
        rating: 5,
        avatar: "🙂"
    },
    {
        text: "Professional, fast, and reliable. They exceeded our expectations in every way possible. Couldn't be happier with the results!",
        name: "Lisa Anderson",
        role: "Marketing Manager",
        rating: 5,
        avatar: "😊"
    },
    {
        text: "Outstanding quality and customer service. The best decision we made for our project. Highly professional team!",
        name: "Mike Chen",
        role: "CEO",
        rating: 5,
        avatar: "😎"
    },
    {
        text: "Incredible attention to detail and creativity. They transformed our vision into reality perfectly. Absolutely amazing work!",
        name: "Emma Wilson",
        role: "Art Director",
        rating: 5,
        avatar: "🤩"
    }
];

// Ambil elemen
const track = document.getElementById('carouselTrack');
const prevBtn = document.getElementById('prevBtn');
const nextBtn = document.getElementById('nextBtn');

// Generate cards dari data
testimonials.forEach(function(t) {
    // Buat stars
    let starsHTML = '';
    for (let i = 0; i < t.rating; i++) {
        starsHTML += '<span class="star">★</span>';
    }
    
    // Buat card
    const cardHTML = `
        <div class="testimonial-card">
            <p class="testimonial-text">${t.text}</p>
            <div class="stars">${starsHTML}</div>
            <div class="profile">
                <div class="avatar">${t.avatar}</div>
                <div class="profile-info">
                    <h4>${t.name}</h4>
                    <p>${t.role}</p>
                </div>
            </div>
        </div>
    `;
    
    track.innerHTML += cardHTML;
});

// Variable untuk tracking posisi
let currentPosition = 0;
let cardWidth = 0;
let cardsVisible = 4; // Berapa card yang terlihat sekaligus
let maxPosition = 0;

// Hitung ukuran dan posisi
function calculateDimensions() {
    const cards = document.querySelectorAll('.testimonial-card');
    if (cards.length > 0) {
        cardWidth = cards[0].offsetWidth + 25; // width card + gap
        
        // Sesuaikan berapa card terlihat berdasarkan screen size
        if (window.innerWidth > 1200) {
            cardsVisible = 4;
        } else if (window.innerWidth > 768) {
            cardsVisible = 3;
        } else if (window.innerWidth > 480) {
            cardsVisible = 2;
        } else {
            cardsVisible = 1;
        }
        
        // Maksimal posisi yang bisa di-scroll
        maxPosition = cards.length - cardsVisible;
    }
}

// Update tampilan tombol (disabled/enabled)
function updateButtons() {
    // Disable prev button kalau di awal
    if (currentPosition <= 0) {
        prevBtn.disabled = true;
    } else {
        prevBtn.disabled = false;
    }
    
    // Disable next button kalau di akhir
    if (currentPosition >= maxPosition) {
        nextBtn.disabled = true;
    } else {
        nextBtn.disabled = false;
    }
}

// Function untuk geser carousel
function moveCarousel(direction) {
    // direction: -1 untuk prev, 1 untuk next
    currentPosition += direction;
    
    // Batasi posisi agar tidak keluar range
    if (currentPosition < 0) {
        currentPosition = 0;
    }
    if (currentPosition > maxPosition) {
        currentPosition = maxPosition;
    }
    
    // Hitung berapa pixel harus geser
    const moveDistance = -(currentPosition * cardWidth);
    
    // Geser track dengan transform
    track.style.transform = `translateX(${moveDistance}px)`;
    
    // Update status tombol
    updateButtons();
}

// Event listener untuk tombol prev
prevBtn.addEventListener('click', function() {
    moveCarousel(-1); // Geser ke kiri
});

// Event listener untuk tombol next
nextBtn.addEventListener('click', function() {
    moveCarousel(1); // Geser ke kanan
});

// Event listener untuk resize window
window.addEventListener('resize', function() {
    calculateDimensions();
    currentPosition = 0;
    track.style.transform = 'translateX(0)';
    updateButtons();
});

// Jalankan saat halaman pertama kali load
calculateDimensions();
updateButtons();