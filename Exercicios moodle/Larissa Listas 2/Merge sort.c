/* descrição funcional:
      1. Ordena valores numericos de um vetor atraves do algoritmo Merge Sort.

   lista de parâmetros:
      1. Dois vetores
      2. Uma variavel contendo o tamanho do vetor

   valores de retorno:
      1. Não há valores definidos para o retorno dessa função.
*/
void mergeSort(int numbers[], int temp[], int array_size)
{
  m_sort(numbers, temp, 0, array_size - 1);
}

/* descrição funcional:
      1. Auxilia na ordenação de valores numericos de um vetor atraves do
      algoritmo Merge Sort.

   lista de parâmetros:
      1. Dois vetores
      2. Duas variaveis inteiras

   valores de retorno:
      1. Não há valores definidos para o retorno dessa função.
*/
void m_sort(int numbers[], int temp[], int left, int right)
{
  int mid;

  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(numbers, temp, left, mid);
    m_sort(numbers, temp, mid + 1, right);

    merge(numbers, temp, left, mid + 1, right);
  }
}

/* descrição funcional:
      1. Auxilia na ordenação de valores numericos de um vetor atraves do
      algoritmo Merge Sort.

   lista de parâmetros:
      1. Dois vetores
      2. Tres variaves inteiras.

   valores de retorno:
      1. Não há valores definidos para o retorno dessa função.
*/
void merge(int numbers[], int temp[], int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;

  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left + 1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }

  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }

  for (i = 0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}