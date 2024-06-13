$(document).ready(function () {
    // '지금 시작하기' 버튼 클릭 시 팝업창 표시
    $('#startButton').click(function () {
        alert("지금 시작합니다!");
    });

    // 네비게이션 링크 클릭 시 부드러운 스크롤 기능 구현
    $('nav a').click(function (event) {
        if (this.hash !== "") {
            event.preventDefault();
            var hash = this.hash;
            $('html, body').animate({
                scrollTop: $(hash).offset().top
            }, 800, function () {
                window.location.hash = hash;
            });
        }
    });

    // 로그인 모달 위치 업데이트 함수
    function updateLoginModalPosition() {
        var loginButtonOffset = $('#loginButton').offset();
        var loginButtonWidth = $('#loginButton').outerWidth();
        var modalWidth = $('#loginModal').outerWidth();

        $('#loginModal').css({
            top: loginButtonOffset.top + $('#loginButton').outerHeight(),
            left: loginButtonOffset.left + loginButtonWidth - modalWidth
        });
    }

    // 로그인 상태 표시 함수
    function showLoggedInState(username) {
        $('#loginButton').hide();
        $('#welcomeMessage').text(username + '님, 환영합니다!').show();
        $('#logoutButton').show();
    }

    // 로그아웃 상태 표시 함수
    function showLoggedOutState() {
        $('#loginButton').show();
        $('#welcomeMessage').hide();
        $('#logoutButton').hide();
    }

    // 로그인 버튼 클릭 시 모달 창 표시 및 위치 업데이트
    $('#loginButton').click(function () {
        $('#loginModal').css('display', 'block');
        updateLoginModalPosition();
    });

    // 모달 창 닫기 버튼 클릭 시 모달 창 숨김
    $('.close').click(function () {
        $('#loginModal').css('display', 'none');
        $('#signup-form').hide();
        $('#loginForm').show();
    });

    // 윈도우 크기 변경 시 모달 위치 업데이트
    $(window).resize(function () {
        if ($('#loginModal').css('display') === 'block') {
            updateLoginModalPosition();
        }
    });

    // 로그인 폼 제출 시 처리
    $('#loginForm').submit(function (event) {
        event.preventDefault();
        var username = $('#username').val();
        alert(username + '님, 환영합니다!');
        $('#loginModal').css('display', 'none');
        showLoggedInState(username);
    });

    // 회원가입 폼 제출 시 처리
    $('#signupForm').submit(function (event) {
        event.preventDefault();
        alert($('#signup-username').val() + '님, 회원가입을 축하합니다!');
        $('#signup-form').hide();
        $('#loginForm').show();
        $('#loginModal').css('display', 'block'); // 회원가입 후 로그인 모달 다시 표시
        updateLoginModalPosition();
    });

    // 회원가입 버튼 클릭 시 회원가입 폼 표시
    $('#showSignupButton').click(function () {
        $('#loginForm').hide();
        $('#signup-form').show();
    });

    // 로그인 버튼 클릭 시 로그인 폼 표시
    $('#showLoginButton').click(function () {
        $('#signup-form').hide();
        $('#loginForm').show();
    });

    // 로그아웃 버튼 클릭 시 처리
    $('#logoutButton').click(function () {
        alert('로그아웃되었습니다.');
        showLoggedOutState();
    });

    // 전화번호 입력 시 자동 포커스 이동 및 숫자만 입력받기
    $('#signup-phone-1, #signup-phone-2, #signup-phone-3').on('input', function () {
        // 현재 입력값에서 숫자만 남기기
        $(this).val($(this).val().replace(/\D/g, ''));
    });

    // 전화번호 입력 시 자동 포커스 이동
    $('#signup-phone-1').on('input', function () {
        if ($(this).val().length >= 3) {
            $('#signup-phone-2').focus();
        }
    });

    $('#signup-phone-2').on('input', function () {
        if ($(this).val().length >= 4) {
            $('#signup-phone-3').focus();
        } else if ($(this).val().length === 0) {
            $('#signup-phone-1').focus();
        }
    });

    $('#signup-phone-3').on('input', function () {
        if ($(this).val().length === 0) {
            $('#signup-phone-2').focus();
        }
    });

    // 슬라이더 설정
    var width = parseInt($('[data-role="slider"]').attr('data-width'));
    var height = parseInt($('[data-role="slider"]').attr('data-height'));
    var count = $('[data-role="slider"] .item').length;

    // 첫 번째와 마지막 슬라이더 아이템 복제
    var firstClone = $('[data-role="slider"] .item').first().clone();
    var lastClone = $('[data-role="slider"] .item').last().clone();
    $('[data-role="slider"] .gallery').append(firstClone);
    $('[data-role="slider"] .gallery').prepend(lastClone);

    // 슬라이더 전체 크기 및 아이템 크기 설정
    var totalItems = count + 2;
    $('[data-role="slider"]').css({
        width: width + 'px',
        height: height + 'px'
    }).find('.gallery').css({
        width: totalItems * width + 'px',
        height: height + 'px',
        display: 'flex',
        transform: 'translateX(' + -width + 'px)'
    }).find('.item').css({
        width: width + 'px',
        height: height + 'px'
    });

    var currentPage = 1;
    var autoSlideInterval;

    // 페이지 변경 함수
    var changePage = function () {
        $('[data-role="slider"] > .gallery').css({
            transition: 'transform 0.5s ease',
            transform: 'translateX(' + (-currentPage * width) + 'px)'
        });
    };

    // 슬라이더 애니메이션 종료 시 처리
    $('[data-role="slider"] > .gallery').on('transitionend', function () {
        if (currentPage === 0) {
            $('[data-role="slider"] > .gallery').css({
                transition: 'none',
                transform: 'translateX(' + -(count * width) + 'px)'
            });
            currentPage = count;
        } else if (currentPage === count + 1) {
            $('[data-role="slider"] > .gallery').css({
                transition: 'none',
                transform: 'translateX(' + -width + 'px)'
            });
            currentPage = 1;
        }
    });

    // 자동 슬라이드 함수
    var autoSlide = function () {
        currentPage = (currentPage + 1) % (count + 2);
        changePage();
    };

    // 자동 슬라이드 타이머 리셋 함수
    var resetAutoSlideTimer = function () {
        clearInterval(autoSlideInterval);
        autoSlideInterval = setInterval(autoSlide, 3000);
    };

    // 왼쪽 버튼 클릭 시 처리
    $('#left-button').click(function () {
        if (currentPage > 0) {
            currentPage = currentPage - 1;
        } else {
            currentPage = count;
        }
        changePage();
        resetAutoSlideTimer();
    });

    // 오른쪽 버튼 클릭 시 처리
    $('#right-button').click(function () {
        if (currentPage < count + 1) {
            currentPage = currentPage + 1;
        } else {
            currentPage = 1;
        }
        changePage();
        resetAutoSlideTimer();
    });

    // 자동 슬라이드 시작
    autoSlideInterval = setInterval(autoSlide, 3000);
    $('[data-role="slider"] .item').eq(currentPage).addClass('active');
});

document.addEventListener('DOMContentLoaded', function () {
    // 네비게이션 버튼 및 콘텐츠 설정
    const buttons = document.querySelectorAll('.nav-button');
    const contents = document.querySelectorAll('.content');

    // 기본으로 'design' 섹션 활성화
    const defaultButton = document.querySelector('.nav-button[data-target="design"]');
    defaultButton.classList.add('active');
    document.getElementById('design').classList.add('active');

    // 네비게이션 버튼 클릭 시 처리
    buttons.forEach(button => {
        button.addEventListener('click', () => {
            const targetId = button.getAttribute('data-target');

            buttons.forEach(btn => {
                btn.classList.remove('active');
            });
            button.classList.add('active');

            contents.forEach(content => {
                if (content.id === targetId) {
                    content.classList.add('active');
                } else {
                    content.classList.remove('active');
                }
            });
        });
    });
});
