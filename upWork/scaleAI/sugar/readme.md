The owner of the shop "Tingam" faced a problem. They came to his store𝑛
man and everyone needs sugar:𝑖
-th (1 ≤ 𝑖 ≤ 𝑛
) wants to buy𝑎𝑖
kilogram of sugar. The store owner does not understand why people need so much sugar, but he knows for sure that all the buyers will not have enough sugar, because he only has𝑚
kilogram of sugar. If a customer cannot buy sugar, he will be upset and will no longer go to the Tingam store.

The store owner doesn't want to lose customers. In order to have enough sugar for everyone, he decided to set a limit𝑘
- the maximum number of kilograms of sugar that one person can buy. Thus, when𝑖
  -th (1 ≤ 𝑖 ≤ 𝑛
  ) a man comes to the store he buys𝑚 𝑖 𝑛 (𝑎𝑖, 𝑘 )
  kilogram of sugar (no more than he needs, but no more than𝑘
  kilogram).

The shop owner wants to sell as much sugar as possible. Help the store owner and find this𝑘
where each buyer gets𝑚 𝑖 𝑛 (𝑎𝑖, 𝑘 )
kilogram of sugar and at the same time the total amount of sugar sold will be maximum, but will not exceed the stock of sugar in the store𝑚
.

Input data
The first line of the input contains two integers𝑛
And𝑚
(1 ≤ 𝑛 ≤105, 𝑛 ≤ 𝑚 <∑𝑛𝑖 = 1𝑎𝑖
) - the number of buyers and the number of kilograms of sugar that is in the store, respectively.

The second line contains𝑛
integers𝑎1,𝑎2, . . . ,𝑎𝑛
(1 ≤𝑎𝑖≤109,∑𝑛𝑖 = 1𝑎𝑖> 𝑛
). Number𝑎𝑖
- the number of kilograms of sugar that wants to buy𝑖
  th buyer.

Output
Output one number𝑘
where each buyer gets𝑚 𝑖 𝑛 (𝑎𝑖, 𝑘 )
kilogram of sugar and at the same time the total amount of sugar sold will be maximum, but will not exceed the stock of sugar in the store𝑚
. It is guaranteed that𝑘
will always be found.