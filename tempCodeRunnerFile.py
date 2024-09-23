from flask import Flask, render_template
import requests
from datetime import datetime

app = Flask(__name__)

# Replace with your actual bot token and chat ID
TELEGRAM_BOT_TOKEN = "7881312497:AAGthKuxmus5Knofssie0WgEGT-fXeOraUI"
TELEGRAM_CHAT_ID = "1275124991"

def send_telegram_message(message):
    url = f"https://api.telegram.org/bot{TELEGRAM_BOT_TOKEN}/sendMessage"
    payload = {
        "chat_id": TELEGRAM_CHAT_ID,
        "text": message
    }
    response = requests.post(url, json=payload)
    return response.json()

# Check-in route
@app.route('/checkin')
def checkin():
    message = 'Employee Checked-In'
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # Send Telegram message
    telegram_response = send_telegram_message(f'{message} at {current_time}')

    if telegram_response.get("ok"):
        print("Check-in message sent successfully")
    else:
        print("Failed to send check-in message", telegram_response)

    # Render the check-in template
    return render_template('index.html', timestamp=current_time)

# Check-out route
@app.route('/checkout')
def checkout():
    message = 'Employee Checked-Out'
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # Send Telegram message
    telegram_response = send_telegram_message(f'{message} at {current_time}')

    if telegram_response.get("ok"):
        print("Check-out message sent successfully")
    else:
        print("Failed to send check-out message", telegram_response)

    # Render the check-out template
    return render_template('checkout.html', timestamp=current_time)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5466)
