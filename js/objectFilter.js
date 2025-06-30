const items = [
  {
    name: "sourav",
    category: "men",
  },
  {
    name: "riya",
    category: "women",
  },
  {
    name: "sameer",
    category: "kids",
  },
];
const categories = ["kids", "men"];

const answer = items.filter((item) => {
  return categories.includes(item.category);
});

console.log(answer);
