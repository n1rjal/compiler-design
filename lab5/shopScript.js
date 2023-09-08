// Sample item data
const itemsArray = [
  { id: 1, title: "Jeans", cost: 40 },
  { id: 2, title: "Cap", cost: 15 },
  { id: 3, title: "Sweater", cost: 50 },
];

const wishlistArray = [];

// Function to display items
function showItems() {
  const itemCollection = document.getElementById("item-collection");
  itemCollection.innerHTML = "";

  for (const item of itemsArray) {
    const li = document.createElement("li");
    li.innerHTML = `<strong>${item.title}</strong><br>Cost: $${item.cost}<br><button onclick="addToWishlist(${item.id})">Add to Wish List</button>`;
    itemCollection.appendChild(li);
  }
}

// Function to add an item to the wish list
function addToWishlist(itemId) {
  const item = itemsArray.find((i) => i.id === itemId);
  if (item) {
    wishlistArray.push(item);
    showWishlistItems();
  }
}

// Function to display wish list items
function showWishlistItems() {
  const wishlistItemsList = document.getElementById("wishlist-items");
  wishlistItemsList.innerHTML = "";

  for (const item of wishlistArray) {
    const li = document.createElement("li");
    li.innerHTML = `${item.title} - $${item.cost}`;
    wishlistItemsList.appendChild(li);
  }
}

// Initial display
showItems();
