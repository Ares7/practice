someDataFrame
      .filter("amount < 1000")
      .map(_ => someMehtod())
      .groupBy("id")
      .agg(max("amount"))
      .map(_ => anotherMethod())
      .filter("id < 200")