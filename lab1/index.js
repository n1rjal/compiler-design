const productSearchForm = document.getElementById("product__search");
const productAddForm = document.getElementById("product__form");

const products = [
  {
    name: "Product 1",
    price: 10,
    description:
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
  },
  {
    name: "Product 2",
    price: 20,
    description:
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
  },
];

function addProduct(product) {
  products.push(product);
  renderList(products);
}

productAddForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const name = document.getElementById("product__name").value;
  const price = document.getElementById("product__price").value;
  const description = document.getElementById("product__description").value;
  addProduct({ name, price, description });
});

productSearchForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const searchInput = document.getElementById("search__input").value;
  const filteredProducts = products.filter((product) => {
    return product.name.includes(searchInput);
  });
  renderList(filteredProducts);
});

function renderList(products) {
  document.getElementById("product__list").innerHTML = "";
  let html = "";
  products.forEach((product) => {
    html += `<div>
            <h3>${product.name} - Rs ${product.price}</h3>
            <p>${product.description}</p>
    </div>`;
  });
  document.getElementById("product__list").innerHTML = html;
}

document.onload = renderList(products);
