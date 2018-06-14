# coding: utf-8


from notes.handlers import hello_handler
from notes.handlers import get_note

route = {
    'Say.Hello': hello_handler,
    'Note.get': get_note,
}
