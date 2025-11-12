# ft_substr.c — Q&A Learning Log

## 🧠 Summary
- Implementation of `ft_substr`, part of the **42 Libft** project.  
- Function goal: return a substring from string `s`, starting at index `start`,  
  with a maximum length of `len`.  
- Allocates memory dynamically (`malloc`) and returns a new string.

---

## ✅ Checklist

- [x] NULL 입력 예외 처리  
- [x] 빈 문자열 반환 (`malloc(1)`)  
- [x] len 클램프 (`if (len > s_len - start)`)  
- [x] malloc 실패 시 NULL 반환  
- [x] 널 종료문자(`'\0'`) 정확히 넣기  
- [x] 호출자(main)에서 `free()` 호출  
- [x] `ft_strlen()` 호출 전 `NULL` 체크  

💡 **주의 포인트:**  
> 🔸 오버플로 방지를 위해 항상 `if (len > s_len - start)` 형태로 비교.  
> 🔸 덧셈(`start + len`)은 오버플로 위험이 있으므로 피해야 함.

---

## 💬 Q&A Highlights

> **Q:** ft_substr의 핵심 역할은 뭐야?  
> **A:** 주어진 문자열 `s`에서 `start` 인덱스부터 최대 `len` 길이만큼 잘라 새로운 문자열을 `malloc`으로 반환하는 함수야.  
> 원본 문자열은 그대로 유지된다.

---

> **Q:** malloc(1)은 왜 필요한 거야?  
> **A:** 빈 문자열을 반환할 때 `'\0'` 하나만 저장할 공간이 필요하기 때문이야.  
> `malloc(0)`은 표준에서 동작이 보장되지 않으므로 최소 1바이트는 확보해야 해.

---

> **Q:** if (start + len > s_len)이 왜 위험해?  
> **A:** `size_t` 덧셈에서 오버플로가 발생할 수 있어.  
> 오버플로가 나면 값이 다시 0부터 돌아가서(`wrap-around`)  
> 논리적으로 `true`가 되어야 할 비교가 `false`로 바뀔 수도 있다.  
> 안전한 비교는 `if (len > s_len - start)`.

---

> **Q:** free()는 왜 함수 안이 아니라 main에서 해야 돼?  
> **A:** `malloc`으로 만든 메모리의 소유권은 호출자에게 있으니까.  
> 함수 내부에서 `free()`하면 `return` 직전에 메모리가 사라져서 세그폴트가 난다.

---

> **Q:** 캐스팅은 필요 없어?  
> **A:** `ft_substr`은 `const char *` 타입을 그대로 쓰기 때문에 필요 없어.  
> 캐스팅은 `void *` 기반의 메모리 함수(`memcpy`, `memcmp`)처럼  
> byte 단위로 접근할 때만 필요해.

---

## 🧪 Test Results
case1 start=7,len=8 -> "42London"
case2 start=0,len=5 -> "Hello"
case3 start=20,len=5 -> ""
case4 start=3,len=50 -> "lo, 42London!"
case5 start=0,len=0 -> ""
✅ **Valgrind 결과:**  
`All heap blocks were freed -- no leaks are possible`

---

## ⚙️ Concepts & Flow

| Concept | Description |
|----------|--------------|
| `malloc(1)` | 빈 문자열(`'\0'`)용 공간 확보 |
| `len > s_len - start` | 오버플로 방지를 위한 안전한 비교 |
| `NULL` 체크 순서 | `ft_strlen()`보다 먼저! |
| `free()`의 책임 | 호출자(main)에서 해야 함 |
| 클램프(Clamp) | 값이 범위를 넘지 않도록 제한 |

---

## 🧱 Reflection

- `size_t` 덧셈 오버플로가 실제로 일어날 수 있다는 걸 처음 체감했다.  
- `malloc(1)`이 단순히 “빈 문자열”을 위한 안전장치임을 이해했다.  
- 함수 내부의 `free()`는 항상 피해야 한다는 원칙을 다시 확인했다.  
- 이번 구현은 정적 타이핑 언어의 안전성과 저수준 메모리 관리를 동시에 연습한 경험이었다.

---

## 📚 Related Functions

| Type | Link |
|------|------|
| Source | [ft_strlen](../src/mandatory/part1/ft_strlen.c) |
| Source | [ft_strjoin](../src/mandatory/part2/ft_strjoin.c) |
| Source | [ft_strtrim](../src/mandatory/part2/ft_strtrim.c) |
| Docs | [ft_strjoin Q&A Log](ft_strjoin_log.md) |
| Docs | [ft_strtrim Q&A Log](ft_strtrim_log.md) |

---

## ✨ Usage
1️⃣ `libft/docs/` 폴더에 `ft_substr_log.md`로 저장  
2️⃣ `README.md`에 링크 추가:

```md
## Learning Logs
- [ft_substr Q&A Log](docs/ft_substr_log.md)