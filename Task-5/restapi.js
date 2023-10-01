const express = require('express');
const bodyParser = require('body-parser');

const app = express();

// Middleware
app.use(bodyParser.json());

const books = [
    { id: 1, title: 'Book 1' },
    { id: 2, title: 'Book 2' },
    { id: 3, title: 'Book 3' },
];

// GET endpoint to retrieve all books
app.get('/books', (req, res) => {
    res.json(books);
});

// POST endpoint to add a new book
app.post('/books', (req, res) => {
    const newBook = req.body;
    books.push(newBook);
    res.sendStatus(201);
});

// GET endpoint to retrieve a specific book by ID
app.get('/books/:id', (req, res) => {
    const bookId = parseInt(req.params.id); // Parse the ID to an integer
    const book = books.find(b => b.id === bookId);
    if (!book) {
        res.status(404).send('Book not found'); // Send a message with 404
    } else {
        res.json(book);
    }
});

// DELETE endpoint to remove a book by ID
app.delete('/books/:id', (req, res) => {
    const bookId = parseInt(req.params.id); // Parse the ID to an integer
    const bookIndex = books.findIndex(b => b.id === bookId);
    if (bookIndex === -1) {
        res.status(404).send('Book not found'); // Send a message with 404
    } else {
        books.splice(bookIndex, 1);
        res.sendStatus(204);
    }
});

// Start the server
app.listen(3000, () => {
    console.log('Server is running on port 3000');
});
