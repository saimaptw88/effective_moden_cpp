## 23項
- ```std::move```, ```std::forward```は何もムーヴしない
- オブジェクトをムーブ元にする際は```const```を使用してもコピーが実行され警告もされない
- ```std::move``` はオブジェクトがムーブ可能であることを保証しない
- ```std::move```: 全てを右辺値にキャストする
- ```std::forward```: 引数が右辺値で初期化されたものの場合のみ右辺値にキャストする

## 24項
- ```T&&```: 右辺値参照とユニバーサル参照の２種類を記述できる
- 型推論を伴わない```T&&```は右辺値参照
- ユニバーサル参照は初期化を必要とし、初期化子によって左辺値参照か右辺値参照かを決定する

## 25項
- 右辺値参照がバインドするのはムーブ可能なオブジェクトのみ
- 仮引数が右辺値参照の場合は```std::move```, ユニバーサル参照の時は```std::forward```

## 26項

## 27項
- ディスパッチ設計で、ユニバーサル参照とオーバーロードの問題を防ぐ
- template有効/無効でも完全転送を実現できる。。。
