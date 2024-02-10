#include "Client.h"

void Client::run()
{

    Config config = readConfig("../config.txt");

    sf::TcpSocket server;

    sf::RenderWindow window(sf::VideoMode(1080, 608), "Blackjack", sf::Style::Close | sf::Style::Titlebar);

    sf::Image icon;
    if (!icon.loadFromFile("Images/ICCON.png"))
    {
        std::cout << "Error loading icon" << std::endl;
    }

    // Set icon for the window
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);

    sf::Cursor cursor;
    cursor.loadFromSystem(sf::Cursor::Type::Arrow);

    // Load textures
    sf::Texture loginTexture;
    sf::Texture registerTexture;
    sf::Texture betTexture;
    sf::Texture gameTexture;
    sf::Texture mapTexture;
    sf::Texture loginWarning;
    sf::Texture usernameWarning;
    sf::Texture passwordWarning;
    sf::Texture betWarning;
    sf::Texture blackjack;
    sf::Texture login_7;
    sf::Texture login_4;
    sf::Texture login_K;
    sf::Texture login_A;
    sf::Texture estorilNameTexture;
    sf::Texture dubaiNameTexture;
    sf::Texture lasVegasNameTexture;
    sf::Texture macauNameTexture;
    sf::Texture pontaDelEsteNameTexture;
    sf::Texture sunCityNameTexture;
    sf::Texture sidneyNameTexture;
    sf::Texture penguinNameTexture;
    sf::Texture estorilTexture;
    sf::Texture antartidaTexture;
    sf::Texture lasvegasTexture;
    sf::Texture sidneyTexture;
    sf::Texture southamericaTexture;
    sf::Texture suncityTexture;
    sf::Texture dubaiTexture;
    sf::Texture macauTexture;
    sf::Texture casinoSelect;

    loginTexture.loadFromFile("images/login.png");
    registerTexture.loadFromFile("images/register.png");
    betTexture.loadFromFile("images/betLayout.png");
    gameTexture.loadFromFile("images/Mesa.png");
    mapTexture.loadFromFile("images/map_.png");
    loginWarning.loadFromFile("images/loginWarning.png");
    usernameWarning.loadFromFile("images/usernameWarning.png");
    passwordWarning.loadFromFile("images/passwordWarning.png");
    betWarning.loadFromFile("images/betWarning.png");
    blackjack.loadFromFile("images/blackjack.png");
    login_7.loadFromFile("images/7.png");
    login_4.loadFromFile("images/4.png");
    login_K.loadFromFile("images/K.png");
    login_A.loadFromFile("images/A.png");
    estorilNameTexture.loadFromFile("images/estoril.png");
    dubaiNameTexture.loadFromFile("images/dubai.png");
    lasVegasNameTexture.loadFromFile("images/LasVegas.png");
    macauNameTexture.loadFromFile("images/macau.png");
    pontaDelEsteNameTexture.loadFromFile("images/pontaDelEste.png");
    sunCityNameTexture.loadFromFile("images/sunCity.png");
    sidneyNameTexture.loadFromFile("images/sidney.png");
    penguinNameTexture.loadFromFile("images/PenguinText.png");
    casinoSelect.loadFromFile("images/casinoSel.png");

    estorilTexture.loadFromFile("images/MesaEstoril.png");
    antartidaTexture.loadFromFile("images/MesaAntartida.png");
    lasvegasTexture.loadFromFile("images/MesaLasVegas.png");
    sidneyTexture.loadFromFile("images/MesaSidney.png");
    southamericaTexture.loadFromFile("images/MesaSouthAmerica.png");
    suncityTexture.loadFromFile("images/MesaSunCity.png");
    dubaiTexture.loadFromFile("images/MesaDubai.png");
    macauTexture.loadFromFile("images/MesaMacau.png");

    //! LOGIN/REGISTER PAGE
    // Create sprites
    sf::Sprite blackjackSprite(blackjack);
    blackjackSprite.setPosition(sf::Vector2f(200, 15));
    sf::Sprite login_7Sprite(login_7);
    login_7Sprite.setPosition(sf::Vector2f(1080, 0));
    sf::Sprite login_4Sprite(login_4);
    login_4Sprite.setPosition(sf::Vector2f(1080, 0));
    sf::Sprite login_KSprite(login_K);
    login_KSprite.setPosition(sf::Vector2f(1080, 182));
    sf::Sprite login_ASprite(login_A);
    login_ASprite.setPosition(sf::Vector2f(1080, 285));

    //! MAP PAGE
    // Create sprites

    sf::Sprite estorilName(estorilNameTexture);
    estorilName.setPosition(sf::Vector2f(457, 130));
    sf::Sprite dubaiName(dubaiNameTexture);
    dubaiName.setPosition(sf::Vector2f(625, 157));
    sf::Sprite lasVegasName(lasVegasNameTexture);
    lasVegasName.setPosition(sf::Vector2f(102, 122));
    sf::Sprite macauName(macauNameTexture);
    macauName.setPosition(sf::Vector2f(795, 167));
    sf::Sprite pontaDelEsteName(pontaDelEsteNameTexture);
    pontaDelEsteName.setPosition(sf::Vector2f(220, 338));
    sf::Sprite sunCityName(sunCityNameTexture);
    sunCityName.setPosition(sf::Vector2f(528, 322));
    sf::Sprite sidneyName(sidneyNameTexture);
    sidneyName.setPosition(sf::Vector2f(930, 320));
    sf::Sprite penguinName(penguinNameTexture);
    penguinName.setPosition(sf::Vector2f(500, 506));

    // sprites at the end of the game
    sf::Texture winTexture;
    winTexture.loadFromFile("images/win.png");
    sf::Texture loseTexture;
    loseTexture.loadFromFile("images/lose.png");
    sf::Texture drawTexture;
    drawTexture.loadFromFile("images/draw.png");
    sf::Texture blackjackTexture;
    blackjackTexture.loadFromFile("images/Blackjack_label.png");

    sf::Sprite endSprite(loseTexture);
    endSprite.setPosition(sf::Vector2f(0, 0));

    sf::Sprite casinoSelectSprite(casinoSelect);
    casinoSelectSprite.setPosition(sf::Vector2f(375, 20));

    // Create variables for animations
    static double login_7X = 1080;
    double login_7Velocity = 0;
    double login_7Acceleration = 0.5;
    double login_4X = 1080;
    double login_4Velocity = 0;
    double login_4Acceleration = 0.5;
    double login_KX = 1080;
    double login_KVelocity = 0;
    double login_KAcceleration = 0.5;
    double login_AX = 1080;
    double login_AVelocity = 0;
    double login_AAcceleration = 0.5;
    double casinoSelectX = 0;
    double casinoSelectVelocity = 0;
    double casinoSelectAcceleration = 0.5;
    double casinoSelectY = 0;


    //! MAP PAGE
    // Create buttons
    int arrow_width = 28;
    int arrow_height = 45;
    ImageButton arrowEstoril("images/arrow.png", 507 - arrow_width, 206 - arrow_height);
    arrowEstoril.setOverImage("images/arrow.png");

    ImageButton arrowDubai("images/arrow.png", 665 - arrow_width, 235 - arrow_width);
    arrowDubai.setOverImage("images/arrow.png");

    ImageButton arrowLasVegas("images/arrow.png", 164 - arrow_width, 202 - arrow_height);
    arrowLasVegas.setOverImage("images/arrow.png");

    ImageButton arrowPontaDelEste("images/arrow.png", 310 - arrow_width, 416 - arrow_height);
    arrowPontaDelEste.setOverImage("images/arrow.png");

    ImageButton arrowMacau("images/arrow.png", 837 - arrow_width, 245 - arrow_height);
    arrowMacau.setOverImage("images/arrow.png");

    ImageButton arrowSunCity("images/arrow.png", 585 - arrow_width, 400 - arrow_height);
    arrowSunCity.setOverImage("images/arrow.png");

    ImageButton arrowSidney("images/arrow.png", 976 - arrow_width, 398 - arrow_height);
    arrowSidney.setOverImage("images/arrow.png");

    ImageButton arrowPenguin("images/Penguin.png", 553 - arrow_width, 583 - arrow_height);
    arrowPenguin.setOverImage("images/Penguin.png");

    sf::Texture arrow;
    arrow.loadFromFile("images/arrow.png");

    sf::Texture lock;
    lock.loadFromFile("images/cadeado.png");

    bool estorilUnlocked = false;
    bool dubaiUnlocked = true;
    bool lasVegasUnlocked = false;
    bool pontaDelEsteUnlocked = false;
    bool macauUnlocked = false;
    bool sunCityUnlocked = false;
    bool sidneyUnlocked = false;
    bool penguinUnlocked = false;

    double arrow_y = 0;
    double arrowVelocity = 0;
    double arrowAcceleration = 0.5;

    sf::Texture hiddenCardTexture;
    hiddenCardTexture.loadFromFile("images/cards/card_back.png");

    // Load font
    sf::Font font;
    font.loadFromFile("minecraft.ttf");

    // Create variables
    sf::Texture *texture = new sf::Texture;
    std::string *page = new std::string("login");

    *texture = loginTexture;

    bool iswarning = false;
    bool isusernameWarning = false;
    double *balance = new double;
    double *bet = new double;
    bool login_entry = true;
    bool end = false;
    int result;
    int result_display;
    int dealerHiddenScore = 0;
    int mesa = ESTORIL;

    bool cardDealing = true;
    // Create buttons
    ImageButton loginButton("images/loginButton.png", 310, 480);
    loginButton.setOverImage("images/loginButtonOver.png");

    ImageButton toRegisterButton("images/toRegisterButton.png", 310, 412);
    toRegisterButton.setOverImage("images/toRegisterButtonOver.png");

    ImageButton registerButton("images/registerButton.png", 310, 480);
    registerButton.setOverImage("images/registerButtonOver.png");

    ImageButton backButton("images/backButton.png", 10, 10);
    backButton.setOverImage("images/backButtonOver.png");

    ImageButton okButton("images/ok.png", 315, 398);
    okButton.setOverImage("images/okOver.png");
    okButton.enabled = false;
    okButton.setOverImage("images/okOver.png");

    // ################## GAME BUTTONS ##################//

    ImageButton hitButton("images/hit.png", 800, 490);
    hitButton.setOverImage("images/hitButtonOver.png");

    ImageButton standButton("images/stand.png", 910, 450);
    standButton.setOverImage("images/standButtonOver.png");

    ImageButton doubleButton("images/double.png", 970, 350);
    doubleButton.setOverImage("images/doubleButtonOver.png");

    ImageButton playAgainButton("images/playAgainButton.png", 360, 430);
    playAgainButton.setOverImage("images/playAgainButtonOver.png");

    // ##################################################//

    ImageButton betButton("images/betButton.png", 445, 493);
    betButton.setOverImage("images/betButtonOver.png");

    ImageButton coin_10("images/10.png", 20, 480);
    coin_10.setOverImage("images/10Over.png");
    ImageButton coin_50("images/50.png", 100, 480);
    coin_50.setOverImage("images/50Over.png");
    ImageButton coin_100("images/100.png", 180, 480);
    coin_100.setOverImage("images/100Over.png");
    ImageButton coin_500("images/500.png", 260, 480);
    coin_500.setOverImage("images/500Over.png");
    ImageButton coin_1000("images/1000.png", 340, 480);
    coin_1000.setOverImage("images/1000Over.png");

    // Create text boxes
    TextBox username(40, sf::Color::Black, false, "Username");
    username.setFont(font);
    username.setPosition(sf::Vector2f(340, 230));
    username.setLimit(true, 17);

    TextBox password(40, sf::Color::Black, false, "Password");
    password.setFont(font);
    password.setPosition(sf::Vector2f(340, 305));
    password.setLimit(true, 17);

    TextBox confirmPassword(40, sf::Color::Black, false, "Confirm Password");
    confirmPassword.setFont(font);
    confirmPassword.setPosition(sf::Vector2f(340, 380));
    confirmPassword.setLimit(true, 17);

    TextBox betAmount(40, sf::Color::Black, false, "Bet Amount: 0");
    betAmount.setFont(font);
    betAmount.setPosition(sf::Vector2f(680, 510));
    betAmount.setLimit(true, 17);

    TextBox balanceAmount(40, sf::Color::Black, false, "0");
    balanceAmount.setFont(font);
    balanceAmount.setPosition(sf::Vector2f(925, 30));
    balanceAmount.setLimit(true, 17);

    TextBox dealerScore(20, sf::Color::White, false, "0");
    dealerScore.setFont(font);
    dealerScore.setPosition(sf::Vector2f(480, 20));

    TextBox gamblerScore(20, sf::Color::White, false, "0");
    gamblerScore.setFont(font);
    gamblerScore.setPosition(sf::Vector2f(480, 375));

    if (server.connect(config.serverIP, config.serverPort) != sf::Socket::Done)
    {
        // Error connecting to server
        std::cerr << "Error connecting to server: " << server.getRemoteAddress() << std::endl;
        return;
    }

    std::cout << "Connected to server" << std::endl;

    cursor.loadFromSystem(sf::Cursor::Type::Arrow);
    while (window.isOpen())
    {
        sf::Event evnt;

        if (*page == "bet")
        {
            if (mesa == ESTORIL)
            {
                *texture = estorilTexture;
            }
            else if (mesa == ANTARTIDA)
            {
                *texture = antartidaTexture;
            }
            else if (mesa == VEGAS)
            {
                *texture = lasvegasTexture;
            }
            else if (mesa == SIDNEY)
            {
                *texture = sidneyTexture;
            }
            else if (mesa == SOUTH_AMERICA)
            {
                *texture = southamericaTexture;
            }
            else if (mesa == SUNCITY)
            {
                *texture = suncityTexture;
            }
            else if(mesa == DUBAI)
            {
                *texture = dubaiTexture;
            }
            else if(mesa == MACAU)
            {
                *texture = macauTexture;
            }
            else
            {
                *texture = gameTexture;
            }
        }
        else if (*page == "game")
        {
            if (mesa == ESTORIL)
            {
                *texture = estorilTexture;
            }
            else if (mesa == ANTARTIDA)
            {
                *texture = antartidaTexture;
            }
            else if (mesa == VEGAS)
            {
                *texture = lasvegasTexture;
            }
            else if (mesa == SIDNEY)
            {
                *texture = sidneyTexture;
            }
            else if (mesa == SOUTH_AMERICA)
            {
                *texture = southamericaTexture;
            }
            else if (mesa == SUNCITY)
            {
                *texture = suncityTexture;
            }
            else if(mesa == DUBAI)
            {
                *texture = dubaiTexture;
            }
            else if(mesa == MACAU)
            {
                *texture = macauTexture;
            }
            else
            {
                *texture = gameTexture;
            }
        }
        else if (*page == "register")
        {
            *texture = registerTexture;
        }
        else if (*page == "login")
        {
            *texture = loginTexture;
        }
        else if (*page == "map")
        {
            *texture = mapTexture;
        }
        else
        {
            std::cout << "Unknown page: " << *page << std::endl;
            return;
        }

        if (*page == "login")
        {
            while (window.pollEvent(evnt))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Arrow);
                if (evnt.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (username.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Text);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        username.setSelected(true);
                        password.setSelected(false);
                        std::cout << "Username selected" << std::endl;
                        std::cout << "Password unselected" << std::endl;
                    }
                }
                if ((evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter) && username.isSelected == true)
                {
                    username.setSelected(false);
                    std::cout << "Username unselected" << std::endl;
                }
                if ((evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Tab) && username.isSelected == true)
                {
                    username.setSelected(false);
                    password.setSelected(true);
                    std::cout << "Username unselected" << std::endl;
                    std::cout << "Password selected" << std::endl;
                }
                if (password.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Text);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        password.setSelected(true);
                        username.setSelected(false);
                        std::cout << "Password selected" << std::endl;
                        std::cout << "Username unselected" << std::endl;
                    }
                }
                if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter && password.isSelected == true)
                {
                    password.setSelected(false);
                    std::cout << "Password unselected" << std::endl;
                }
                if (evnt.type == sf::Event::TextEntered)
                {
                    username.typedOn(evnt);
                    password.typedOn(evnt);
                }
                if (loginButton.isClicked(window) && !iswarning)
                {
                    std::cout << "Login button clicked" << std::endl;
                    std::string *usernameStr = new std::string(username.getText());
                    std::string *passwordStr = new std::string(password.getText());
                    int status = login(server, page, balance, usernameStr, passwordStr);
                    if (status == 0)
                    {
                        iswarning = true;
                        okButton.enabled = true;
                        username.setSelected(false);
                        password.setSelected(false);
                    }
                    else if (status == 1)
                    {
                        std::cout << "Login successful" << std::endl;
                        std::cout << "Balance: " << *balance << std::endl;
                    }
                    else
                    {
                        server.disconnect();
                        return;
                    }
                }
                if (toRegisterButton.isClicked(window) && !iswarning)
                {
                    *page = "register";
                    login_entry = true;
                    login_7Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_4Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_KSprite.setPosition(sf::Vector2f(1080, 182));
                    login_ASprite.setPosition(sf::Vector2f(1080, 285));

                    login_7X = 1080;
                    login_7Velocity = 0;
                    login_7Acceleration = 0.5;
                    login_4X = 1080;
                    login_4Velocity = 0;
                    login_4Acceleration = 0.5;
                    login_KX = 1080;
                    login_KVelocity = 0;
                    login_KAcceleration = 0.5;
                    login_AX = 1080;
                    login_AVelocity = 0;
                    login_AAcceleration = 0.5;

                    break;
                }
                if (iswarning && okButton.isClicked(window))
                {
                    iswarning = false;
                    okButton.enabled = false;
                    username.setText("username");
                    password.setText("password");
                }
            }

            if (login_entry)
            {

                if (login_7Sprite.getPosition().x > 985)
                {

                    if (login_7X >= 985)
                    {
                        login_7Acceleration = -0.5;
                    }
                    else if (login_7X <= 985)
                    {
                        login_7X = 985;
                    }
                    login_7Velocity += login_7Acceleration;
                    login_7X += login_7Velocity;
                    login_7Sprite.setPosition(sf::Vector2f(login_7X, 0));
                }
                else
                {
                    login_7Sprite.setPosition(sf::Vector2f(985, 0));
                }

                if (login_7Sprite.getPosition().x <= 1000 && login_4Sprite.getPosition().x > 925)
                {

                    if (login_4X >= 925)
                    {
                        login_4Acceleration = -0.5;
                    }
                    else if (login_4X <= 925)
                    {
                        login_4X = 925;
                    }
                    login_4Velocity += login_4Acceleration;
                    login_4X += login_4Velocity;
                    login_4Sprite.setPosition(sf::Vector2f(login_4X, 0));
                }
                else if (login_4Sprite.getPosition().x <= 925)
                {
                    login_4Sprite.setPosition(sf::Vector2f(925, 0));
                }

                if (login_4Sprite.getPosition().x <= 1000 && login_KSprite.getPosition().x > 865)
                {

                    if (login_KX >= 865)
                    {
                        login_KAcceleration = -0.5;
                    }
                    else if (login_KX <= 865)
                    {
                        login_KX = 865;
                    }
                    login_KVelocity += login_KAcceleration;
                    login_KX += login_KVelocity;
                    login_KSprite.setPosition(sf::Vector2f(login_KX, 182));
                }
                else if (login_KSprite.getPosition().x <= 865)
                {
                    login_KSprite.setPosition(sf::Vector2f(865, 182));
                }

                if (login_KSprite.getPosition().x <= 1000 && login_ASprite.getPosition().x > 805)
                {
                    if (login_AX >= 805)
                    {
                        login_AAcceleration = -0.5;
                    }
                    else if (login_AX <= 805)
                    {
                        login_AX = 805;
                    }
                    login_AVelocity += login_AAcceleration;
                    login_AX += login_AVelocity;
                    login_ASprite.setPosition(sf::Vector2f(login_AX, 285));
                }
                else if (login_ASprite.getPosition().x <= 805)
                {
                    login_ASprite.setPosition(sf::Vector2f(805, 285));
                }

                if (login_7Sprite.getPosition().x <= 985 && login_4Sprite.getPosition().x <= 925 && login_KSprite.getPosition().x <= 865 && login_ASprite.getPosition().x <= 805)
                {
                    login_entry = false;
                }
            }

            static double blackjackY = 10;
            static double blackjackVelocity = 0;
            static double blackjackAcceleration = 0.025;
            if (blackjackY >= 15)
            {
                blackjackAcceleration = -0.025;
            }
            else if (blackjackY <= 15)
            {
                blackjackAcceleration = 0.025;
            }
            blackjackVelocity += blackjackAcceleration;
            blackjackY += blackjackVelocity;
            blackjackSprite.setPosition(sf::Vector2f(200, blackjackY));

            loginButton.update(window);
            toRegisterButton.update(window);
            okButton.update(window);

            window.clear();
            if (loginButton.isMouseOver(window) || toRegisterButton.isMouseOver(window) || okButton.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
            }
            window.setMouseCursor(cursor);

            sf::Sprite sprite(*texture);
            window.draw(sprite);

            window.draw(blackjackSprite);

            window.draw(login_7Sprite);
            window.draw(login_4Sprite);
            window.draw(login_KSprite);
            window.draw(login_ASprite);

            loginButton.draw(window);
            toRegisterButton.draw(window);

            password.drawTo(window);
            username.drawTo(window);

            if (iswarning)
            {
                sf::Sprite sprite(loginWarning);
                window.draw(sprite);
                okButton.draw(window);
            }

            window.display();
        }
        else if (*page == "register")
        {
            while (window.pollEvent(evnt))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Arrow);
                if (evnt.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (username.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Text);

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        username.setSelected(true);
                        password.setSelected(false);
                        confirmPassword.setSelected(false);
                        std::cout << "Username selected" << std::endl;
                        std::cout << "Password unselected" << std::endl;
                        std::cout << "Confirm Password unselected" << std::endl;
                    }
                }
                if ((evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter) && username.isSelected == true)
                {
                    username.setSelected(false);
                    std::cout << "Username unselected" << std::endl;
                }
                if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Tab)
                {
                    if (username.isSelected)
                    {
                        username.setSelected(false);
                        password.setSelected(true);
                        confirmPassword.setSelected(false);
                        std::cout << "Username unselected" << std::endl;
                        std::cout << "Password selected" << std::endl;
                    }
                    else if (password.isSelected)
                    {
                        username.setSelected(false);
                        password.setSelected(false);
                        confirmPassword.setSelected(true);
                        std::cout << "Password unselected" << std::endl;
                        std::cout << "Confirm Password selected" << std::endl;
                    }
                    else if (confirmPassword.isSelected)
                    {
                        username.setSelected(true);
                        password.setSelected(false);
                        confirmPassword.setSelected(false);
                        std::cout << "Confirm Password unselected" << std::endl;
                        std::cout << "Username selected" << std::endl;
                    }
                }
                if (password.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Text);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        password.setSelected(true);
                        username.setSelected(false);
                        confirmPassword.setSelected(false);
                        std::cout << "Password selected" << std::endl;
                        std::cout << "Username unselected" << std::endl;
                        std::cout << "Confirm Password unselected" << std::endl;
                    }
                }
                if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter && password.isSelected == true)
                {
                    password.setSelected(false);
                    std::cout << "Password unselected" << std::endl;
                }
                if (confirmPassword.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Text);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        confirmPassword.setSelected(true);
                        username.setSelected(false);
                        password.setSelected(false);
                        std::cout << "Confirm Password selected" << std::endl;
                        std::cout << "Username unselected" << std::endl;
                        std::cout << "Password unselected" << std::endl;
                    }
                }
                if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter && confirmPassword.isSelected == true)
                {
                    confirmPassword.setSelected(false);
                    std::cout << "Confirm Password unselected" << std::endl;
                }
                if (evnt.type == sf::Event::TextEntered)
                {
                    username.typedOn(evnt);
                    password.typedOn(evnt);
                    confirmPassword.typedOn(evnt);
                }
                if (registerButton.isClicked(window) && !iswarning && !isusernameWarning)
                {
                    std::string *usernameStr = new std::string(username.getText());
                    std::string *passwordStr = new std::string(password.getText());
                    std::string *confirmPasswordStr = new std::string(confirmPassword.getText());

                    if (*passwordStr != *confirmPasswordStr)
                    {
                        delete usernameStr;
                        delete passwordStr;
                        delete confirmPasswordStr;
                        iswarning = true;
                        okButton.enabled = true;
                    }
                    else if (registerAccount(server, page, balance, usernameStr, passwordStr, confirmPasswordStr) == 0)
                    {
                        isusernameWarning = true;
                        okButton.enabled = true;
                    }
                    else
                    {
                        std::cout << "Registration successful" << std::endl;
                        std::cout << "Balance: " << *balance << std::endl;
                    }
                }
                if (backButton.isClicked(window) && !iswarning && !isusernameWarning)
                {
                    *page = "login";
                    confirmPassword.setSelected(false);
                    username.setSelected(false);
                    password.setSelected(false);
                    okButton.enabled = false;
                    login_entry = true;

                    login_7Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_4Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_KSprite.setPosition(sf::Vector2f(1080, 182));
                    login_ASprite.setPosition(sf::Vector2f(1080, 285));

                    login_7X = 1080;
                    login_7Velocity = 0;
                    login_7Acceleration = 0.5;
                    login_4X = 1080;
                    login_4Velocity = 0;
                    login_4Acceleration = 0.5;
                    login_KX = 1080;
                    login_KVelocity = 0;
                    login_KAcceleration = 0.5;
                    login_AX = 1080;
                    login_AVelocity = 0;
                    login_AAcceleration = 0.5;

                    break;
                }
                if (iswarning && okButton.isClicked(window))
                {
                    iswarning = false;
                    username.setText("username");
                    password.setText("password");
                    confirmPassword.setText("confirm password");
                    okButton.enabled = false;
                }
                if (isusernameWarning && okButton.isClicked(window))
                {
                    isusernameWarning = false;
                    username.setText("username");
                    password.setText("password");
                    confirmPassword.setText("confirm password");
                    okButton.enabled = false;
                }
            }

            if (login_entry)
            {

                if (login_7Sprite.getPosition().x > 985)
                {

                    if (login_7X >= 985)
                    {
                        login_7Acceleration = -0.5;
                    }
                    else if (login_7X <= 985)
                    {
                        login_7X = 985;
                    }
                    login_7Velocity += login_7Acceleration;
                    login_7X += login_7Velocity;
                    login_7Sprite.setPosition(sf::Vector2f(login_7X, 0));
                }
                else
                {
                    login_7Sprite.setPosition(sf::Vector2f(985, 0));
                }

                if (login_7Sprite.getPosition().x <= 1000 && login_4Sprite.getPosition().x > 925)
                {

                    if (login_4X >= 925)
                    {
                        login_4Acceleration = -0.5;
                    }
                    else if (login_4X <= 925)
                    {
                        login_4X = 925;
                    }
                    login_4Velocity += login_4Acceleration;
                    login_4X += login_4Velocity;
                    login_4Sprite.setPosition(sf::Vector2f(login_4X, 0));
                }
                else if (login_4Sprite.getPosition().x <= 925)
                {
                    login_4Sprite.setPosition(sf::Vector2f(925, 0));
                }

                if (login_4Sprite.getPosition().x <= 1000 && login_KSprite.getPosition().x > 865)
                {

                    if (login_KX >= 865)
                    {
                        login_KAcceleration = -0.5;
                    }
                    else if (login_KX <= 865)
                    {
                        login_KX = 865;
                    }
                    login_KVelocity += login_KAcceleration;
                    login_KX += login_KVelocity;
                    login_KSprite.setPosition(sf::Vector2f(login_KX, 182));
                }
                else if (login_KSprite.getPosition().x <= 865)
                {
                    login_KSprite.setPosition(sf::Vector2f(865, 182));
                }

                if (login_KSprite.getPosition().x <= 1000 && login_ASprite.getPosition().x > 805)
                {
                    if (login_AX >= 805)
                    {
                        login_AAcceleration = -0.5;
                    }
                    else if (login_AX <= 805)
                    {
                        login_AX = 805;
                    }
                    login_AVelocity += login_AAcceleration;
                    login_AX += login_AVelocity;
                    login_ASprite.setPosition(sf::Vector2f(login_AX, 285));
                }
                else if (login_ASprite.getPosition().x <= 805)
                {
                    login_ASprite.setPosition(sf::Vector2f(805, 285));
                }

                if (login_7Sprite.getPosition().x <= 985 && login_4Sprite.getPosition().x <= 925 && login_KSprite.getPosition().x <= 865 && login_ASprite.getPosition().x <= 805)
                {
                    login_entry = false;
                }
            }

            static double blackjackY = 10;
            static double blackjackVelocity = 0;
            static double blackjackAcceleration = 0.025;
            if (blackjackY >= 15)
            {
                blackjackAcceleration = -0.025;
            }
            else if (blackjackY <= 15)
            {
                blackjackAcceleration = 0.025;
            }
            blackjackVelocity += blackjackAcceleration;
            blackjackY += blackjackVelocity;
            blackjackSprite.setPosition(sf::Vector2f(200, blackjackY));

            registerButton.update(window);
            backButton.update(window);
            okButton.update(window);

            window.clear();

            if (loginButton.isMouseOver(window) || toRegisterButton.isMouseOver(window) || okButton.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
            }
            window.setMouseCursor(cursor);

            sf::Sprite sprite(*texture);
            window.draw(sprite);

            window.draw(login_7Sprite);
            window.draw(login_4Sprite);
            window.draw(login_KSprite);
            window.draw(login_ASprite);

            window.draw(blackjackSprite);

            registerButton.draw(window);
            backButton.draw(window);

            username.drawTo(window);
            password.drawTo(window);
            confirmPassword.drawTo(window);

            if (iswarning)
            {
                sf::Sprite sprite(passwordWarning);
                window.draw(sprite);
                okButton.draw(window);
            }
            else if (isusernameWarning)
            {
                sf::Sprite sprite(usernameWarning);
                window.draw(sprite);
                okButton.draw(window);
            }

            window.display();
        }
        else if (*page == "map")
        {
            penguinUnlocked = true;
            dubaiUnlocked = true;
            lasVegasUnlocked = *balance > 5000;
            macauUnlocked = *balance > 10000;
            pontaDelEsteUnlocked = *balance > 15000;
            sidneyUnlocked = *balance > 20000;
            sunCityUnlocked = *balance > 25000;
            estorilUnlocked = *balance > 30000;

            arrowDubai.sprite.setTexture((dubaiUnlocked) ? arrow : lock);
            arrowLasVegas.sprite.setTexture((lasVegasUnlocked) ? arrow : lock);
            arrowMacau.sprite.setTexture((macauUnlocked) ? arrow : lock);
            arrowPontaDelEste.sprite.setTexture((pontaDelEsteUnlocked) ? arrow : lock);
            arrowSidney.sprite.setTexture((sidneyUnlocked) ? arrow : lock);
            //arrowPenguin.sprite.setTexture((penguinUnlocked) ? arrow : lock);
            arrowSunCity.sprite.setTexture((sunCityUnlocked) ? arrow : lock);
            arrowEstoril.sprite.setTexture((estorilUnlocked) ? arrow : lock);

            while (window.pollEvent(evnt))
            {
                if (evnt.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (backButton.isClicked(window))
                {
                    *page = "login";
                    login_entry = true;

                    login_7Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_4Sprite.setPosition(sf::Vector2f(1080, 0));
                    login_KSprite.setPosition(sf::Vector2f(1080, 182));
                    login_ASprite.setPosition(sf::Vector2f(1080, 285));
                    break;
                }
                if (arrowEstoril.isClicked(window) && estorilUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = ESTORIL;
                }
                else if (arrowDubai.isClicked(window) && dubaiUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = DUBAI;
                }
                else if (arrowLasVegas.isClicked(window) && lasVegasUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = VEGAS;
                }
                else if (arrowMacau.isClicked(window) && macauUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = MACAU;
                }
                else if (arrowPontaDelEste.isClicked(window) && pontaDelEsteUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = SOUTH_AMERICA;
                }
                else if (arrowSidney.isClicked(window) && sidneyUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = SIDNEY;
                }
                else if (arrowSunCity.isClicked(window) && sunCityUnlocked)
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = SUNCITY;
                }
                else if (arrowPenguin.isClicked(window))
                {
                    *bet = 0;
                    *page = "bet";
                    mesa = ANTARTIDA;
                }
            }

            if (arrow_y > 0)
            {
                arrowAcceleration = -0.05;
            }
            else if (arrow_y < 0)
            {
                arrowAcceleration = 0.05;
            }

            arrowVelocity += arrowAcceleration;
            arrow_y += arrowVelocity;

            arrowEstoril.sprite.setPosition(sf::Vector2f(arrowEstoril.sprite.getPosition().x, 206 - arrow_height + estorilUnlocked * arrow_y));
            arrowDubai.sprite.setPosition(sf::Vector2f(arrowDubai.sprite.getPosition().x, 235 - arrow_height + dubaiUnlocked * arrow_y));
            arrowLasVegas.sprite.setPosition(sf::Vector2f(arrowLasVegas.sprite.getPosition().x, 202 - arrow_height + lasVegasUnlocked * arrow_y));
            arrowPontaDelEste.sprite.setPosition(sf::Vector2f(arrowPontaDelEste.sprite.getPosition().x, 416 - arrow_height + pontaDelEsteUnlocked * arrow_y));
            arrowMacau.sprite.setPosition(sf::Vector2f(arrowMacau.sprite.getPosition().x, 245 - arrow_height + macauUnlocked * arrow_y));
            arrowSunCity.sprite.setPosition(sf::Vector2f(arrowSunCity.sprite.getPosition().x, 400 - arrow_height + sunCityUnlocked * arrow_y));
            arrowSidney.sprite.setPosition(sf::Vector2f(arrowSidney.sprite.getPosition().x, 398 - arrow_height + sidneyUnlocked * arrow_y));
            //arrowPenguin.sprite.setPosition(sf::Vector2f(arrowPenguin.sprite.getPosition().x, 583 - arrow_height));
            // PINGU NÃO TEM ARROW_Y

            backButton.update(window);

            if (casinoSelectY > 0)
            {
                casinoSelectAcceleration = -0.025;
            }
            else if (casinoSelectY < 0)
            {
                casinoSelectAcceleration = 0.025;
            }

            casinoSelectVelocity += casinoSelectAcceleration;
            casinoSelectY += casinoSelectVelocity;

            casinoSelectSprite.setPosition(sf::Vector2f(casinoSelectSprite.getPosition().x, 10 + casinoSelectY));


            window.clear();

            sf::Sprite sprite(*texture);
            window.draw(sprite);
            cursor.loadFromSystem(sf::Cursor::Type::Arrow);

            window.draw(casinoSelectSprite);

            if (arrowEstoril.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(estorilName);
                arrowEstoril.sprite.setPosition(sf::Vector2f(arrowEstoril.sprite.getPosition().x, 206 - arrow_height));
            }
            else if (arrowDubai.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(dubaiName);
                arrowDubai.sprite.setPosition(sf::Vector2f(arrowDubai.sprite.getPosition().x, 235 - arrow_height));
            }
            else if (arrowLasVegas.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(lasVegasName);
                arrowLasVegas.sprite.setPosition(sf::Vector2f(arrowLasVegas.sprite.getPosition().x, 202 - arrow_height));
            }
            else if (arrowMacau.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(macauName);
                arrowMacau.sprite.setPosition(sf::Vector2f(arrowMacau.sprite.getPosition().x, 245 - arrow_height));
            }
            else if (arrowPontaDelEste.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(pontaDelEsteName);
                arrowPontaDelEste.sprite.setPosition(sf::Vector2f(arrowPontaDelEste.sprite.getPosition().x, 416 - arrow_height));
            }
            else if (arrowSidney.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(sidneyName);
                arrowSidney.sprite.setPosition(sf::Vector2f(arrowSidney.sprite.getPosition().x, 398 - arrow_height));
            }
            else if (arrowSunCity.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(sunCityName);
                arrowSunCity.sprite.setPosition(sf::Vector2f(arrowSunCity.sprite.getPosition().x, 400 - arrow_height));
            }
            else if (arrowPenguin.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
                window.draw(penguinName);
                arrowPenguin.sprite.setPosition(sf::Vector2f(arrowPenguin.sprite.getPosition().x, 583 - arrow_height));
            }
            else if (backButton.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
            }

            backButton.draw(window);
            arrowEstoril.draw(window);
            arrowDubai.draw(window);
            arrowLasVegas.draw(window);
            arrowPontaDelEste.draw(window);
            arrowMacau.draw(window);
            arrowSunCity.draw(window);
            arrowSidney.draw(window);
            arrowPenguin.draw(window);

            window.setMouseCursor(cursor);

            window.display();
        }
        else if (*page == "bet")
        {

            while (window.pollEvent(evnt))
            {
                if (evnt.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (backButton.isClicked(window))
                {
                    *balance += *bet;
                    *bet = 0;
                    *page = "map";
                }
                if (coin_10.isClicked(window) && *balance >= 10)
                {
                    *balance -= 10;
                    *bet += 10;
                }
                if (coin_50.isClicked(window) && *balance >= 50)
                {
                    *balance -= 50;
                    *bet += 50;
                }
                if (coin_100.isClicked(window) && *balance >= 100)
                {
                    *balance -= 100;
                    *bet += 100;
                }
                if (coin_500.isClicked(window) && *balance >= 500)
                {
                    *balance -= 500;
                    *bet += 500;
                }
                if (coin_1000.isClicked(window) && *balance >= 1000)
                {
                    *balance -= 1000;
                    *bet += 1000;
                }
                if (betButton.isClicked(window))
                {
                    if (*bet == 0)
                    {
                        iswarning = true;
                        okButton.enabled = true;
                    }
                    else
                    {
                        std::string *betStr = new std::string(std::to_string(static_cast<int>(*bet)));
                        std::cout << "Bet: " << *betStr << std::endl;
                        try
                        {
                            sendMessage(server, "bet " + *betStr);
                            std::string *message = new std::string(receiveMessage(server));
                            std::istringstream data(*message);
                            std::string *token = new std::string;
                            std::string *balanceStr = new std::string;
                            std::string *newPage = new std::string;

                            data >> *token >> *balanceStr >> *newPage;
                            if (*token == "success")
                            {

                                std::cout << "Bet successful" << std::endl;
                                try
                                {
                                    *balance = std::stod(*balanceStr);
                                }
                                catch (std::invalid_argument)
                                {
                                    std::cout << "Invalid balance" << std::endl;
                                    continue;
                                }
                                *page = *newPage;

                                std::cout << "Balance: " << *balance << std::endl;
                                delete token;
                                delete balanceStr;
                                delete newPage;
                                delete message;
                            }
                            else if (*token == "failed")
                            {
                                std::cout << "Bet failed" << std::endl;
                                delete token;
                                delete balanceStr;
                                delete newPage;
                                delete message;
                            }
                            else
                            {
                                std::cout << "Unknown response from server: " << message << std::endl;
                            }
                        }
                        catch (std::invalid_argument)
                        {
                            std::cout << "Invalid bet" << std::endl;
                            delete betStr;
                            delete bet;
                        }
                        *page = "game";
                        end = false;
                        backButton.enabled = true;
                        hitButton.enabled = true;
                        standButton.enabled = true;
                        doubleButton.enabled = true;
                        cardDealing = true;
                        playAgainButton.enabled = false;
                    }
                }
                if (iswarning && okButton.isClicked(window))
                {
                    okButton.enabled = false;
                    iswarning = false;
                }
            }

            window.clear();
            backButton.update(window);
            betButton.update(window);
            okButton.update(window);
            coin_10.update(window);
            coin_50.update(window);
            coin_100.update(window);
            coin_500.update(window);
            coin_1000.update(window);
            balanceAmount.setText(std::to_string(static_cast<int>(*balance)));
            betAmount.setText("Bet amount: " + std::to_string(static_cast<int>(*bet)));

            if (okButton.isMouseOver(window) || betButton.isMouseOver(window) || backButton.isMouseOver(window) || coin_10.isMouseOver(window) || coin_50.isMouseOver(window) || coin_100.isMouseOver(window) || coin_500.isMouseOver(window) || coin_1000.isMouseOver(window))
            {
                cursor.loadFromSystem(sf::Cursor::Type::Hand);
            }
            else
            {
                cursor.loadFromSystem(sf::Cursor::Type::Arrow);
            }

            window.setMouseCursor(cursor);

            sf::Sprite sprite(*texture);
            window.draw(sprite);

            sf::Sprite sprite2(betTexture);
            window.draw(sprite2);

            backButton.draw(window);
            betButton.draw(window);
            coin_10.draw(window);
            coin_50.draw(window);
            coin_100.draw(window);
            coin_500.draw(window);
            coin_1000.draw(window);

            betAmount.drawTo(window);
            balanceAmount.drawTo(window);

            if (iswarning)
            {
                sf::Sprite sprite(betWarning);
                window.draw(sprite);
                okButton.draw(window);
            }

            window.display();
        }
        else if (*page == "game")
        {
            sf::Event evnt;
            sendMessage(server, "game");

            std::string *message = new std::string(receiveMessage(server));
            std::istringstream data(*message);

            std::string *token = new std::string;
            std::string *dealer = new std::string;
            std::string *gambler = new std::string;

            data >> *token >> *dealer >> *gambler >> *page;

            bool action = false;
            bool inGame = true;

            std::vector<char> dealer_suits;
            std::vector<char> dealer_ranks;
            std::vector<char> gambler_suits;
            std::vector<char> gambler_ranks;
            int dealerValue;
            int gamblerValue;
            while (inGame)
            {
                backButton.enabled = false;
                hitButton.enabled = true;
                standButton.enabled = true;
                doubleButton.enabled = true;
                playAgainButton.enabled = false;
                std::string *move = new std::string;

                while (window.pollEvent(evnt))
                {
                    if (evnt.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                    /* else if (backButton.isClicked(window) && backButton.enabled)
                    {
                        *page = "map";
                        *bet = 0;
                    } */
                    else if (hitButton.isClicked(window) && hitButton.enabled)
                    {
                        *move = "h";
                        action = true;
                    }
                    else if (standButton.isClicked(window) && standButton.enabled)
                    {
                        *move = "s";
                        action = true;
                    }
                    else if (doubleButton.isClicked(window) && doubleButton.enabled)
                    {
                        *move = "d";
                        action = true;
                    }
                }

                if (action)
                {
                    sendMessage(server, *move);
                    delete message;
                    message = new std::string(receiveMessage(server));

                    data.str(*message);
                    data.clear();

                    data >> *token;

                    if (*token == "win")
                    {
                        result = 0;
                        end = true;
                        data >> *dealer >> *gambler >> *balance;
                        inGame = false;
                        if(gamblerValue == 21){
                            result_display = 3;
                        }
                        else{
                            result_display = 0;
                        }
                    }
                    else if (*token == "lose")
                    {
                        result = 1;
                        end = true;
                        data >> *dealer >> *gambler >> *balance;
                        inGame = false;
                        result_display = 1;
                    }
                    else if (*token == "draw")
                    {
                        result = 2;
                        end = true;
                        data >> *dealer >> *gambler >> *balance;
                        inGame = false;
                        result_display = 2;
                    }
                    else
                    {
                        data >> *dealer >> *gambler;
                    }

                    action = false;
                }

                delete move;

                dealer_suits.clear();
                dealer_ranks.clear();
                gambler_suits.clear();
                gambler_ranks.clear();

                getCardsFromMessage(&dealer_suits, &dealer_ranks, &gambler_suits, &gambler_ranks, dealer, gambler, &dealerValue, &gamblerValue);

                std::cout << "gambler: " << *gambler << std::endl;

                // backButton.update(window);
                hitButton.update(window);
                standButton.update(window);
                doubleButton.update(window);

                if (!end)
                {
                    if (dealer_ranks[1] == 'A')
                    {
                        dealerHiddenScore = 11;
                    }
                    else if (dealer_ranks[1] == 'J' || dealer_ranks[1] == 'Q' || dealer_ranks[1] == 'K' || dealer_ranks[1] == '1')
                    {
                        dealerHiddenScore = 10;
                    }
                    else
                    {
                        dealerHiddenScore = dealer_ranks[1] - '0';
                    }
                }
                else
                {
                    dealerHiddenScore = 0;
                }

                std::cout << "delarHidden: " << dealerHiddenScore << " dealerValue: " << dealerValue << std::endl;

                dealerScore.setText("Hand Value: " + std::to_string(dealerValue - dealerHiddenScore));
                gamblerScore.setText("Hand Value: " + std::to_string(gamblerValue));

                window.clear();

                if (hitButton.isMouseOver(window) || standButton.isMouseOver(window) || doubleButton.isMouseOver(window) /*  || backButton.isMouseOver(window) */)
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Hand);
                }
                else
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Arrow);
                }

                window.setMouseCursor(cursor);
                sf::Sprite sprite(*texture);
                window.draw(sprite);

                loadCards(dealer_suits, dealer_ranks, gambler_suits, gambler_ranks, &window);

                sf::Sprite hiddenCardSprite(hiddenCardTexture);
                hiddenCardSprite.setPosition(sf::Vector2f(545, 50));

                // backButton.draw(window);
                hitButton.draw(window);
                standButton.draw(window);
                doubleButton.draw(window);

                dealerScore.drawTo(window);
                gamblerScore.drawTo(window);

                if (!end)
                {
                    window.draw(hiddenCardSprite);
                }
                window.display();

                if (end)
                {
                    sf::sleep(sf::seconds(1.5));
                    *bet = 0;
                }
            }
            while (true)
            {
                backButton.enabled = true;
                hitButton.enabled = false;
                standButton.enabled = false;
                doubleButton.enabled = false;
                while (window.pollEvent(evnt))
                {
                    if (evnt.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                    else if (playAgainButton.isClicked(window) && playAgainButton.enabled)
                    {
                        *page = "bet";
                        break;
                    }
                    else if (backButton.isClicked(window))
                    {
                        *page = "map";
                        *bet = 0;
                        break;
                    }
                }

                if (*page == "bet" || *page == "map")
                {
                    break;
                }

                backButton.sprite.setTexture(backButton.normalTexture);
                hitButton.sprite.setTexture(hitButton.normalTexture);
                standButton.sprite.setTexture(standButton.normalTexture);
                doubleButton.sprite.setTexture(doubleButton.normalTexture);
                playAgainButton.update(window);
                backButton.update(window);

                window.clear();
                if (playAgainButton.isMouseOver(window) || backButton.isMouseOver(window))
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Hand);
                }
                else
                {
                    cursor.loadFromSystem(sf::Cursor::Type::Arrow);
                }

                window.setMouseCursor(cursor);

                sf::RectangleShape overlay(sf::Vector2f(window.getSize().x, window.getSize().y));
                overlay.setFillColor(sf::Color(0, 0, 0, 150));

                sf::Sprite sprite(*texture);
                window.draw(sprite);

                loadCards(dealer_suits, dealer_ranks, gambler_suits, gambler_ranks, &window);
                doubleButton.draw(window);
                hitButton.draw(window);
                standButton.draw(window);
                window.draw(overlay);
                backButton.draw(window);
                
                if(*balance >= 5000 && mesa == VEGAS || 
                   *balance >= 10000 && mesa == MACAU ||
                   *balance >= 15000 && mesa == SOUTH_AMERICA || 
                   *balance >= 20000 && mesa == SIDNEY || 
                   *balance >= 25000 && mesa == SUNCITY || 
                   *balance >= 30000 && mesa == ESTORIL ||
                   mesa == ANTARTIDA || mesa == DUBAI)
                {

                    playAgainButton.draw(window);
                    playAgainButton.enabled = true;
                }
                else{
                    playAgainButton.enabled = false;
                }

                if (result_display == 0)
                {
                    sf::Sprite sprite(winTexture);
                    sprite.setPosition(sf::Vector2f(0, 0));
                    window.draw(sprite);
                }
                else if (result_display == 1)
                {
                    sf::Sprite sprite(loseTexture);
                    sprite.setPosition(sf::Vector2f(0, 0));
                    window.draw(sprite);
                }
                else if (result_display == 2)
                {
                    sf::Sprite sprite(drawTexture);
                    sprite.setPosition(sf::Vector2f(0, 0));
                    window.draw(sprite);
                }
                else if (result_display == 3)
                {
                    sf::Sprite sprite(blackjackTexture);
                    sprite.setPosition(sf::Vector2f(0, 200));
                    window.draw(sprite);
                }

                window.display();
            }
        }
    }

    server.disconnect();
}

void Client::sendMessage(sf::TcpSocket &server, std::string message)
{

    if (server.send(message.c_str(), message.size()) != sf::Socket::Done)
    {
        // Error sending message
        std::cerr << "Error sending message to server: " << server.getRemoteAddress() << std::endl;
    }
}

std::string Client::receiveMessage(sf::TcpSocket &server)
{

    char buffer[1024];
    std::size_t received;
    if (server.receive(buffer, sizeof(buffer), received) != sf::Socket::Done)
    {
        // Error receiving message
        std::cerr << "Error receiving message from server: " << server.getRemoteAddress() << std::endl;
    }

    return std::string(buffer, received);
}

int Client::registerAccount(sf::TcpSocket &server, std::string *page, double *balance, std::string *username, std::string *password, std::string *confirmPassword)
{

    while (true)
    {

        if (*password != *confirmPassword)
        {
            std::cout << "Passwords do not match" << std::endl;
            delete username;
            delete password;
            delete confirmPassword;
            continue;
        }

        sendMessage(server, "register " + *username + " " + *password);

        delete username;
        delete password;
        delete confirmPassword;

        std::string *message = new std::string(receiveMessage(server));

        std::string *token = new std::string;
        std::string *balanceStr = new std::string;

        std::istringstream data(*message);
        data >> *token;

        if (*token == "success")
        {
            std::cout << "Registration successful" << std::endl;
            data >> *balanceStr >> *page;
            try
            {
                *balance = std::stoi(*balanceStr);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid balance" << std::endl;
                return -1;
            }

            std::cout << "Balance: " << *balance << std::endl;
            delete balanceStr;
            delete token;
            delete message;
            return 1;
        }
        else if (*token == "failed")
        {
            std::cout << "Registration failed" << std::endl;
            delete balanceStr;
            delete token;
            delete message;
            return 0;
        }
        else
        {
            std::cout << "Unknown response from server: " << message << std::endl;
            return -1;
        }
    }

    return -1;
}

int Client::login(sf::TcpSocket &server, std::string *page, double *balance, std::string *username, std::string *password)
{

    while (true)
    {

        std::cout << "Username: " << *username << std::endl;
        std::cout << "Password: " << *password << std::endl;

        sendMessage(server, "login " + *username + " " + *password);

        delete username;
        delete password;

        std::string *message = new std::string(receiveMessage(server));

        std::string *token = new std::string;
        std::string *balanceStr = new std::string;

        std::istringstream data(*message);
        data >> *token;

        if (*token == "success")
        {
            std::cout << "Login successful" << std::endl;
            data >> *balanceStr >> *page;
            try
            {
                *balance = std::stoi(*balanceStr);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid balance" << std::endl;
                return -1;
            }

            std::cout << "Balance: " << *balance << std::endl;
            delete balanceStr;
            delete token;
            delete message;
            return 1;
        }
        else if (*token == "success_admin")
        {
            std::cout << "Super User Login successful" << std::endl;
            data >> *balanceStr >> *page;
            try
            {
                *balance = std::stoi(*balanceStr);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid balance" << std::endl;
                return -1;
            }
            delete balanceStr;
            delete token;
            delete message;
            return 1;
        }
        else if (*token == "failed")
        {
            std::cout << "Login failed" << std::endl;
            delete balanceStr;
            delete token;
            delete message;
            return 0;
        }
        else
        {
            std::cout << "Unknown response from server: " << message << std::endl;
            return -1;
        }
    }

    return -1;
}

int Client::bet(sf::TcpSocket &server, std::string *page, double *balance)
{

    while (true)
    {

        std::cout << "Input the amount you want to bet: ";
        std::string *betStr = new std::string;
        std::cin >> *betStr;
        double *bet = new double;
        if (*betStr == "0")
        {
            continue;
        }

        try
        {
            *bet = std::stod(*betStr);
            sendMessage(server, "bet " + *betStr);
            std::string *message = new std::string(receiveMessage(server));
            std::istringstream data(*message);
            std::string *token = new std::string;
            std::string *balanceStr = new std::string;
            std::string *newPage = new std::string;

            data >> *token >> *balanceStr >> *newPage;
            if (*token == "success")
            {

                std::cout << "Bet successful" << std::endl;
                try
                {
                    *balance = std::stod(*balanceStr);
                }
                catch (std::invalid_argument)
                {
                    std::cout << "Invalid balance" << std::endl;
                    continue;
                }
                *page = *newPage;

                std::cout << "Balance: " << *balance << std::endl;
                delete token;
                delete balanceStr;
                delete newPage;
                delete message;
                return 1;
            }
            else if (*token == "failed")
            {
                std::cout << "Bet failed" << std::endl;
                delete token;
                delete balanceStr;
                delete newPage;
                delete message;
            }
            else
            {
                std::cout << "Unknown response from server: " << message << std::endl;
                return -1;
            }
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid bet" << std::endl;
            delete betStr;
            delete bet;
        }
    }
}

int Client::game(sf::TcpSocket &server, std::string *page, double *balance, sf::RenderWindow window, ImageButton hitButton, ImageButton standButton, ImageButton doubleButton)
{

    sf::Event evnt;

    sendMessage(server, "game");
    std::string *message = new std::string(receiveMessage(server));
    std::istringstream data(*message);

    std::string *token = new std::string;
    std::string *dealer = new std::string;
    std::string *gambler = new std::string;

    data >> *token >> *dealer >> *gambler >> *page;

    std::cout << "Dealer: " << *dealer << std::endl;
    std::cout << "Gambler: " << *gambler << std::endl;

    while (*page == "game")
    {
        std::string *move = new std::string;

        while (window.pollEvent(evnt))
        {
            if (hitButton.isClicked(window))
            {
                *move = "h";
            }
            else if (standButton.isClicked(window))
            {
                *move = "s";
            }
            else if (doubleButton.isClicked(window))
            {
                *move = "d";
            }
        }

        // std::cout << "Input your move (h-hit; s-stand; d-double): ";

        /* while (true)
        {
            std::cin >> *move;
            if (*move == "h" || *move == "s" || *move == "d")
            {
                break;
            }
            else
            {
                std::cout << "Invalid move" << std::endl;
                std::cout << "Input your move (h-hit; s-stand; d-double): ";
            }
        }
 */
        sendMessage(server, *move);

        delete message;
        message = new std::string(receiveMessage(server));

        data.str(*message);
        data.clear();

        data >> *token;

        if (*token == "win")
        {
            data >> *dealer >> *gambler >> *balance;
            std::cout << "Dealer: " << *dealer << std::endl;
            std::cout << "Gambler: " << *gambler << std::endl;
            std::cout << "You win" << std::endl;
            std::cout << "Balance: " << *balance << std::endl;
        }
        else if (*token == "lose")
        {
            data >> *dealer >> *gambler >> *balance;
            std::cout << "Dealer: " << *dealer << std::endl;
            std::cout << "Gambler: " << *gambler << std::endl;
            std::cout << "You lose" << std::endl;
            std::cout << "Balance: " << *balance << std::endl;
        }
        else if (*token == "draw")
        {
            data >> *dealer >> *gambler >> *balance;
            std::cout << "Dealer: " << *dealer << std::endl;
            std::cout << "Gambler: " << *gambler << std::endl;
            std::cout << "Draw" << std::endl;
            std::cout << "Balance: " << *balance << std::endl;
        }
        else
        {
            data >> *dealer >> *gambler;
            std::cout << "Dealer: " << *dealer << std::endl;
            std::cout << "Gambler: " << *gambler << std::endl;
        }

        data >> *page;

        delete move;
    }

    delete message;
    delete token;
    delete dealer;
    delete gambler;

    return 0;
}

bool Client::loadCards(std::vector<char> dealerSuits, std::vector<char> dealerRanks, std::vector<char> gamblerSuits, std::vector<char> gamblerRanks, sf ::RenderWindow *window)
{
    std::vector<sf::Sprite> dealerCards;
    std::vector<sf::Sprite> gamblerCards;

    for (int i = 0; i < dealerSuits.size(); i++)
    {
        sf::Texture cardTexture;
        sf::Sprite cardSprite;
        if (!cardTexture.loadFromFile("images/cards/" + std::string(1, dealerSuits[i]) + "/" + std::string(1, dealerRanks[i]) + ".png"))
        {
            std::cout << "Failed to load card texture!" << std::endl;
            return false;
        }

        cardSprite.setTexture(cardTexture);
        dealerCards.push_back(cardSprite);
        dealerCards[i].setPosition(sf::Vector2f(520 - (dealerSuits.size() - 1) * 25 + 50 * i, 50));
        window->draw(dealerCards[i]);
    }

    for (int i = 0; i < gamblerSuits.size(); i++)
    {
        sf::Texture cardTexture;
        sf::Sprite cardSprite;
        if (!cardTexture.loadFromFile("images/cards/" + std::string(1, gamblerSuits[i]) + "/" + std::string(1, gamblerRanks[i]) + ".png"))
        {
            std::cout << "Failed to load card texture!" << std::endl;
            return false;
        }
        cardSprite.setTexture(cardTexture);
        gamblerCards.push_back(cardSprite);
        gamblerCards[i].setPosition(sf::Vector2f(520 - (gamblerSuits.size() - 1) * 25 + 50 * i, 400));
        window->draw(gamblerCards[i]);
    }

    return true;
}

bool Client::getCardsFromMessage(std::vector<char> *dealerSuits, std::vector<char> *dealerRanks, std::vector<char> *gamblerSuits, std::vector<char> *gamblerRanks, std::string *dealer, std::string *gambler, int *dealerValue, int *gamblerValue)
{
    std::string msg_part;
    std::istringstream msg_dealer(*dealer);
    char aux;
    std::stringstream ss;

    while (true)
    {
        auto cond = !std::getline(msg_dealer, msg_part, ',');
        ss.str(msg_part);
        ss >> aux;

        if (cond || (aux != 'D' && aux != 'H' && aux != 'S' && aux != 'C'))
        {
            if (aux != 'D' && aux != 'H' && aux != 'S' && aux != 'C')
            {
                *dealerValue = std::stoi(msg_part);
            }
            break;
        }
        dealerSuits->push_back(aux);
        ss >> aux;
        dealerRanks->push_back(aux);
    }

    std::istringstream msg_gambler(*gambler);
    while (true)
    {
        auto cond = !std::getline(msg_gambler, msg_part, ',');
        ss.str(msg_part);
        ss >> aux;

        if (cond || (aux != 'D' && aux != 'H' && aux != 'S' && aux != 'C'))
        {
            if (aux != 'D' && aux != 'H' && aux != 'S' && aux != 'C')
            {
                *gamblerValue = std::stoi(msg_part);
            }
            break;
        };
        gamblerSuits->push_back(aux);
        ss >> aux;
        gamblerRanks->push_back(aux);
    }

    return true;
}

bool Client::animateSprite(sf::Sprite *sprite, sf::Vector2f destination, int speed, sf::RenderWindow *window, sf::Texture *texture)
{
    // Calculate the distance between current position and destination
    sf::Vector2f distance = destination - sprite->getPosition();

    // Calculate the magnitude of the distance vector
    float magnitude = sqrt(distance.x * distance.x + distance.y * distance.y);

    // Calculate the normalized direction vector
    sf::Vector2f direction = distance / magnitude;

    sf::Sprite txtr(*texture);

    // Main loop for sprite movement
    while (magnitude > speed)
    {
        // Move the sprite according to the direction and speed
        sprite->move(direction * static_cast<float>(speed * 2));

        // Clear the window, draw the sprite, and display
        window->clear();
        window->draw(txtr);
        window->draw(*sprite);
        window->display();

        // Calculate the updated distance and magnitude
        distance = destination - sprite->getPosition();
        magnitude = sqrt(distance.x * distance.x + distance.y * distance.y);
    }

    // Move the sprite to the exact destination and draw
    sprite->setPosition(destination);
    window->clear();
    window->draw(txtr);
    window->draw(*sprite);
    window->display();

    return true;
}

Client::Config Client::readConfig(const std::string &filename)
{
    Config config;
    std::ifstream configFile(filename);

    if (configFile.is_open())
    {
        std::string line;
        while (std::getline(configFile, line))
        {
            std::istringstream iss(line);
            std::string key, separator, value;

            iss >> key >> separator;

            if (key == "ServerIP=")
            {
                config.serverIP = separator;
            }
            else if (key == "ServerPort=")
            {
                config.serverPort = std::stoi(separator);
            }
        }
        configFile.close();
    }
    else
    {
        std::cerr << "Unable to open config file: " << filename << std::endl;
    }

    return config;
}
