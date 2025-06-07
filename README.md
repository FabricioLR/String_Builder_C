# String Builder

![GitHub repo size](https://img.shields.io/github/repo-size/FabricioLR/String_Builder_C?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/FabricioLR/String_Builder_C?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/FabricioLR/String_Builder_C?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/FabricioLR/String_Builder_C?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/FabricioLR/String_Builder_C?style=for-the-badge)

> Implementação de um string builder escrito em C.

## 🚀 Instalando

Apenas copie o arquivo ![string_builder.h](https://github.com/FabricioLR/String_Builder_C/blob/master/string_builder.h) para dentro do seu projeto

## ☕ Usando

```
#include "string_builder.h"


int main(){
  StringBuilder *sb = stringBuilder_init("hello, world");

	printf("initial sb: %s\n", toString(sb));

	append(sb, "  teste - teste");
	printf("appended: %s\n", toString(sb));
	insert(sb, 0, "ola");
	printf("inserted: %s\n", toString(sb));
  ...
```

Saída esperada

```
$./example
  initial sb: hello, world
  appended: hello, world  teste - teste
  inserted: olahello, world  teste - teste
```


## 📫 Contribuindo

Para contribuir, siga estas etapas:

1. Fork este repositório.
2. Crie um branch: `git checkout -b <nome_branch>`.
3. Faça suas alterações e confirme-as: `git commit -m '<mensagem_commit>'`
4. Envie para o branch original: `git push origin <nome_do_projeto> / <local>`
5. Crie um Pull Request.

Como alternativa, consulte a documentação do GitHub em [como criar uma solicitação pull](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).
