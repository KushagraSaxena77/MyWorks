from flask import Flask, request
import threading
import concurrent.futures

app = Flask(__name__)

executor = concurrent.futures.ThreadPoolExecutor()

@app.route('/get', methods=['GET'])
def handle_get_request():
    return "This is a GET request"

@app.route('/post', methods=['POST'])
def handle_post_request():
    return "This is a POST request"

@app.route('/head', methods=['HEAD'])
def handle_head_request():
    return "This is a HEAD request"

@app.route('/delete', methods=['DELETE'])
def handle_delete_request():
    return "This is a DELETE request"

if __name__ == '__main__':
    app.run(threaded=True)
