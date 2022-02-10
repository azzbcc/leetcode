char *target[] = {
    "1/2",    "1/3",    "1/4",    "1/5",    "1/6",    "1/7",    "1/8",    "1/9",    "1/10",   "1/11",   "1/12",
    "1/13",   "1/14",   "1/15",   "1/16",   "1/17",   "1/18",   "1/19",   "1/20",   "1/21",   "1/22",   "1/23",
    "1/24",   "1/25",   "1/26",   "1/27",   "1/28",   "1/29",   "1/30",   "1/31",   "1/32",   "1/33",   "1/34",
    "1/35",   "1/36",   "1/37",   "1/38",   "1/39",   "1/40",   "1/41",   "1/42",   "1/43",   "1/44",   "1/45",
    "1/46",   "1/47",   "1/48",   "1/49",   "1/50",   "1/51",   "1/52",   "1/53",   "1/54",   "1/55",   "1/56",
    "1/57",   "1/58",   "1/59",   "1/60",   "1/61",   "1/62",   "1/63",   "1/64",   "1/65",   "1/66",   "1/67",
    "1/68",   "1/69",   "1/70",   "1/71",   "1/72",   "1/73",   "1/74",   "1/75",   "1/76",   "1/77",   "1/78",
    "1/79",   "1/80",   "1/81",   "1/82",   "1/83",   "1/84",   "1/85",   "1/86",   "1/87",   "1/88",   "1/89",
    "1/90",   "1/91",   "1/92",   "1/93",   "1/94",   "1/95",   "1/96",   "1/97",   "1/98",   "1/99",   "1/100",
    "2/3",    "2/5",    "2/7",    "2/9",    "2/11",   "2/13",   "2/15",   "2/17",   "2/19",   "2/21",   "2/23",
    "2/25",   "2/27",   "2/29",   "2/31",   "2/33",   "2/35",   "2/37",   "2/39",   "2/41",   "2/43",   "2/45",
    "2/47",   "2/49",   "2/51",   "2/53",   "2/55",   "2/57",   "2/59",   "2/61",   "2/63",   "2/65",   "2/67",
    "2/69",   "2/71",   "2/73",   "2/75",   "2/77",   "2/79",   "2/81",   "2/83",   "2/85",   "2/87",   "2/89",
    "2/91",   "2/93",   "2/95",   "2/97",   "2/99",   "3/4",    "3/5",    "3/7",    "3/8",    "3/10",   "3/11",
    "3/13",   "3/14",   "3/16",   "3/17",   "3/19",   "3/20",   "3/22",   "3/23",   "3/25",   "3/26",   "3/28",
    "3/29",   "3/31",   "3/32",   "3/34",   "3/35",   "3/37",   "3/38",   "3/40",   "3/41",   "3/43",   "3/44",
    "3/46",   "3/47",   "3/49",   "3/50",   "3/52",   "3/53",   "3/55",   "3/56",   "3/58",   "3/59",   "3/61",
    "3/62",   "3/64",   "3/65",   "3/67",   "3/68",   "3/70",   "3/71",   "3/73",   "3/74",   "3/76",   "3/77",
    "3/79",   "3/80",   "3/82",   "3/83",   "3/85",   "3/86",   "3/88",   "3/89",   "3/91",   "3/92",   "3/94",
    "3/95",   "3/97",   "3/98",   "3/100",  "4/5",    "4/7",    "4/9",    "4/11",   "4/13",   "4/15",   "4/17",
    "4/19",   "4/21",   "4/23",   "4/25",   "4/27",   "4/29",   "4/31",   "4/33",   "4/35",   "4/37",   "4/39",
    "4/41",   "4/43",   "4/45",   "4/47",   "4/49",   "4/51",   "4/53",   "4/55",   "4/57",   "4/59",   "4/61",
    "4/63",   "4/65",   "4/67",   "4/69",   "4/71",   "4/73",   "4/75",   "4/77",   "4/79",   "4/81",   "4/83",
    "4/85",   "4/87",   "4/89",   "4/91",   "4/93",   "4/95",   "4/97",   "4/99",   "5/6",    "5/7",    "5/8",
    "5/9",    "5/11",   "5/12",   "5/13",   "5/14",   "5/16",   "5/17",   "5/18",   "5/19",   "5/21",   "5/22",
    "5/23",   "5/24",   "5/26",   "5/27",   "5/28",   "5/29",   "5/31",   "5/32",   "5/33",   "5/34",   "5/36",
    "5/37",   "5/38",   "5/39",   "5/41",   "5/42",   "5/43",   "5/44",   "5/46",   "5/47",   "5/48",   "5/49",
    "5/51",   "5/52",   "5/53",   "5/54",   "5/56",   "5/57",   "5/58",   "5/59",   "5/61",   "5/62",   "5/63",
    "5/64",   "5/66",   "5/67",   "5/68",   "5/69",   "5/71",   "5/72",   "5/73",   "5/74",   "5/76",   "5/77",
    "5/78",   "5/79",   "5/81",   "5/82",   "5/83",   "5/84",   "5/86",   "5/87",   "5/88",   "5/89",   "5/91",
    "5/92",   "5/93",   "5/94",   "5/96",   "5/97",   "5/98",   "5/99",   "6/7",    "6/11",   "6/13",   "6/17",
    "6/19",   "6/23",   "6/25",   "6/29",   "6/31",   "6/35",   "6/37",   "6/41",   "6/43",   "6/47",   "6/49",
    "6/53",   "6/55",   "6/59",   "6/61",   "6/65",   "6/67",   "6/71",   "6/73",   "6/77",   "6/79",   "6/83",
    "6/85",   "6/89",   "6/91",   "6/95",   "6/97",   "7/8",    "7/9",    "7/10",   "7/11",   "7/12",   "7/13",
    "7/15",   "7/16",   "7/17",   "7/18",   "7/19",   "7/20",   "7/22",   "7/23",   "7/24",   "7/25",   "7/26",
    "7/27",   "7/29",   "7/30",   "7/31",   "7/32",   "7/33",   "7/34",   "7/36",   "7/37",   "7/38",   "7/39",
    "7/40",   "7/41",   "7/43",   "7/44",   "7/45",   "7/46",   "7/47",   "7/48",   "7/50",   "7/51",   "7/52",
    "7/53",   "7/54",   "7/55",   "7/57",   "7/58",   "7/59",   "7/60",   "7/61",   "7/62",   "7/64",   "7/65",
    "7/66",   "7/67",   "7/68",   "7/69",   "7/71",   "7/72",   "7/73",   "7/74",   "7/75",   "7/76",   "7/78",
    "7/79",   "7/80",   "7/81",   "7/82",   "7/83",   "7/85",   "7/86",   "7/87",   "7/88",   "7/89",   "7/90",
    "7/92",   "7/93",   "7/94",   "7/95",   "7/96",   "7/97",   "7/99",   "7/100",  "8/9",    "8/11",   "8/13",
    "8/15",   "8/17",   "8/19",   "8/21",   "8/23",   "8/25",   "8/27",   "8/29",   "8/31",   "8/33",   "8/35",
    "8/37",   "8/39",   "8/41",   "8/43",   "8/45",   "8/47",   "8/49",   "8/51",   "8/53",   "8/55",   "8/57",
    "8/59",   "8/61",   "8/63",   "8/65",   "8/67",   "8/69",   "8/71",   "8/73",   "8/75",   "8/77",   "8/79",
    "8/81",   "8/83",   "8/85",   "8/87",   "8/89",   "8/91",   "8/93",   "8/95",   "8/97",   "8/99",   "9/10",
    "9/11",   "9/13",   "9/14",   "9/16",   "9/17",   "9/19",   "9/20",   "9/22",   "9/23",   "9/25",   "9/26",
    "9/28",   "9/29",   "9/31",   "9/32",   "9/34",   "9/35",   "9/37",   "9/38",   "9/40",   "9/41",   "9/43",
    "9/44",   "9/46",   "9/47",   "9/49",   "9/50",   "9/52",   "9/53",   "9/55",   "9/56",   "9/58",   "9/59",
    "9/61",   "9/62",   "9/64",   "9/65",   "9/67",   "9/68",   "9/70",   "9/71",   "9/73",   "9/74",   "9/76",
    "9/77",   "9/79",   "9/80",   "9/82",   "9/83",   "9/85",   "9/86",   "9/88",   "9/89",   "9/91",   "9/92",
    "9/94",   "9/95",   "9/97",   "9/98",   "9/100",  "10/11",  "10/13",  "10/17",  "10/19",  "10/21",  "10/23",
    "10/27",  "10/29",  "10/31",  "10/33",  "10/37",  "10/39",  "10/41",  "10/43",  "10/47",  "10/49",  "10/51",
    "10/53",  "10/57",  "10/59",  "10/61",  "10/63",  "10/67",  "10/69",  "10/71",  "10/73",  "10/77",  "10/79",
    "10/81",  "10/83",  "10/87",  "10/89",  "10/91",  "10/93",  "10/97",  "10/99",  "11/12",  "11/13",  "11/14",
    "11/15",  "11/16",  "11/17",  "11/18",  "11/19",  "11/20",  "11/21",  "11/23",  "11/24",  "11/25",  "11/26",
    "11/27",  "11/28",  "11/29",  "11/30",  "11/31",  "11/32",  "11/34",  "11/35",  "11/36",  "11/37",  "11/38",
    "11/39",  "11/40",  "11/41",  "11/42",  "11/43",  "11/45",  "11/46",  "11/47",  "11/48",  "11/49",  "11/50",
    "11/51",  "11/52",  "11/53",  "11/54",  "11/56",  "11/57",  "11/58",  "11/59",  "11/60",  "11/61",  "11/62",
    "11/63",  "11/64",  "11/65",  "11/67",  "11/68",  "11/69",  "11/70",  "11/71",  "11/72",  "11/73",  "11/74",
    "11/75",  "11/76",  "11/78",  "11/79",  "11/80",  "11/81",  "11/82",  "11/83",  "11/84",  "11/85",  "11/86",
    "11/87",  "11/89",  "11/90",  "11/91",  "11/92",  "11/93",  "11/94",  "11/95",  "11/96",  "11/97",  "11/98",
    "11/100", "12/13",  "12/17",  "12/19",  "12/23",  "12/25",  "12/29",  "12/31",  "12/35",  "12/37",  "12/41",
    "12/43",  "12/47",  "12/49",  "12/53",  "12/55",  "12/59",  "12/61",  "12/65",  "12/67",  "12/71",  "12/73",
    "12/77",  "12/79",  "12/83",  "12/85",  "12/89",  "12/91",  "12/95",  "12/97",  "13/14",  "13/15",  "13/16",
    "13/17",  "13/18",  "13/19",  "13/20",  "13/21",  "13/22",  "13/23",  "13/24",  "13/25",  "13/27",  "13/28",
    "13/29",  "13/30",  "13/31",  "13/32",  "13/33",  "13/34",  "13/35",  "13/36",  "13/37",  "13/38",  "13/40",
    "13/41",  "13/42",  "13/43",  "13/44",  "13/45",  "13/46",  "13/47",  "13/48",  "13/49",  "13/50",  "13/51",
    "13/53",  "13/54",  "13/55",  "13/56",  "13/57",  "13/58",  "13/59",  "13/60",  "13/61",  "13/62",  "13/63",
    "13/64",  "13/66",  "13/67",  "13/68",  "13/69",  "13/70",  "13/71",  "13/72",  "13/73",  "13/74",  "13/75",
    "13/76",  "13/77",  "13/79",  "13/80",  "13/81",  "13/82",  "13/83",  "13/84",  "13/85",  "13/86",  "13/87",
    "13/88",  "13/89",  "13/90",  "13/92",  "13/93",  "13/94",  "13/95",  "13/96",  "13/97",  "13/98",  "13/99",
    "13/100", "14/15",  "14/17",  "14/19",  "14/23",  "14/25",  "14/27",  "14/29",  "14/31",  "14/33",  "14/37",
    "14/39",  "14/41",  "14/43",  "14/45",  "14/47",  "14/51",  "14/53",  "14/55",  "14/57",  "14/59",  "14/61",
    "14/65",  "14/67",  "14/69",  "14/71",  "14/73",  "14/75",  "14/79",  "14/81",  "14/83",  "14/85",  "14/87",
    "14/89",  "14/93",  "14/95",  "14/97",  "14/99",  "15/16",  "15/17",  "15/19",  "15/22",  "15/23",  "15/26",
    "15/28",  "15/29",  "15/31",  "15/32",  "15/34",  "15/37",  "15/38",  "15/41",  "15/43",  "15/44",  "15/46",
    "15/47",  "15/49",  "15/52",  "15/53",  "15/56",  "15/58",  "15/59",  "15/61",  "15/62",  "15/64",  "15/67",
    "15/68",  "15/71",  "15/73",  "15/74",  "15/76",  "15/77",  "15/79",  "15/82",  "15/83",  "15/86",  "15/88",
    "15/89",  "15/91",  "15/92",  "15/94",  "15/97",  "15/98",  "16/17",  "16/19",  "16/21",  "16/23",  "16/25",
    "16/27",  "16/29",  "16/31",  "16/33",  "16/35",  "16/37",  "16/39",  "16/41",  "16/43",  "16/45",  "16/47",
    "16/49",  "16/51",  "16/53",  "16/55",  "16/57",  "16/59",  "16/61",  "16/63",  "16/65",  "16/67",  "16/69",
    "16/71",  "16/73",  "16/75",  "16/77",  "16/79",  "16/81",  "16/83",  "16/85",  "16/87",  "16/89",  "16/91",
    "16/93",  "16/95",  "16/97",  "16/99",  "17/18",  "17/19",  "17/20",  "17/21",  "17/22",  "17/23",  "17/24",
    "17/25",  "17/26",  "17/27",  "17/28",  "17/29",  "17/30",  "17/31",  "17/32",  "17/33",  "17/35",  "17/36",
    "17/37",  "17/38",  "17/39",  "17/40",  "17/41",  "17/42",  "17/43",  "17/44",  "17/45",  "17/46",  "17/47",
    "17/48",  "17/49",  "17/50",  "17/52",  "17/53",  "17/54",  "17/55",  "17/56",  "17/57",  "17/58",  "17/59",
    "17/60",  "17/61",  "17/62",  "17/63",  "17/64",  "17/65",  "17/66",  "17/67",  "17/69",  "17/70",  "17/71",
    "17/72",  "17/73",  "17/74",  "17/75",  "17/76",  "17/77",  "17/78",  "17/79",  "17/80",  "17/81",  "17/82",
    "17/83",  "17/84",  "17/86",  "17/87",  "17/88",  "17/89",  "17/90",  "17/91",  "17/92",  "17/93",  "17/94",
    "17/95",  "17/96",  "17/97",  "17/98",  "17/99",  "17/100", "18/19",  "18/23",  "18/25",  "18/29",  "18/31",
    "18/35",  "18/37",  "18/41",  "18/43",  "18/47",  "18/49",  "18/53",  "18/55",  "18/59",  "18/61",  "18/65",
    "18/67",  "18/71",  "18/73",  "18/77",  "18/79",  "18/83",  "18/85",  "18/89",  "18/91",  "18/95",  "18/97",
    "19/20",  "19/21",  "19/22",  "19/23",  "19/24",  "19/25",  "19/26",  "19/27",  "19/28",  "19/29",  "19/30",
    "19/31",  "19/32",  "19/33",  "19/34",  "19/35",  "19/36",  "19/37",  "19/39",  "19/40",  "19/41",  "19/42",
    "19/43",  "19/44",  "19/45",  "19/46",  "19/47",  "19/48",  "19/49",  "19/50",  "19/51",  "19/52",  "19/53",
    "19/54",  "19/55",  "19/56",  "19/58",  "19/59",  "19/60",  "19/61",  "19/62",  "19/63",  "19/64",  "19/65",
    "19/66",  "19/67",  "19/68",  "19/69",  "19/70",  "19/71",  "19/72",  "19/73",  "19/74",  "19/75",  "19/77",
    "19/78",  "19/79",  "19/80",  "19/81",  "19/82",  "19/83",  "19/84",  "19/85",  "19/86",  "19/87",  "19/88",
    "19/89",  "19/90",  "19/91",  "19/92",  "19/93",  "19/94",  "19/96",  "19/97",  "19/98",  "19/99",  "19/100",
    "20/21",  "20/23",  "20/27",  "20/29",  "20/31",  "20/33",  "20/37",  "20/39",  "20/41",  "20/43",  "20/47",
    "20/49",  "20/51",  "20/53",  "20/57",  "20/59",  "20/61",  "20/63",  "20/67",  "20/69",  "20/71",  "20/73",
    "20/77",  "20/79",  "20/81",  "20/83",  "20/87",  "20/89",  "20/91",  "20/93",  "20/97",  "20/99",  "21/22",
    "21/23",  "21/25",  "21/26",  "21/29",  "21/31",  "21/32",  "21/34",  "21/37",  "21/38",  "21/40",  "21/41",
    "21/43",  "21/44",  "21/46",  "21/47",  "21/50",  "21/52",  "21/53",  "21/55",  "21/58",  "21/59",  "21/61",
    "21/62",  "21/64",  "21/65",  "21/67",  "21/68",  "21/71",  "21/73",  "21/74",  "21/76",  "21/79",  "21/80",
    "21/82",  "21/83",  "21/85",  "21/86",  "21/88",  "21/89",  "21/92",  "21/94",  "21/95",  "21/97",  "21/100",
    "22/23",  "22/25",  "22/27",  "22/29",  "22/31",  "22/35",  "22/37",  "22/39",  "22/41",  "22/43",  "22/45",
    "22/47",  "22/49",  "22/51",  "22/53",  "22/57",  "22/59",  "22/61",  "22/63",  "22/65",  "22/67",  "22/69",
    "22/71",  "22/73",  "22/75",  "22/79",  "22/81",  "22/83",  "22/85",  "22/87",  "22/89",  "22/91",  "22/93",
    "22/95",  "22/97",  "23/24",  "23/25",  "23/26",  "23/27",  "23/28",  "23/29",  "23/30",  "23/31",  "23/32",
    "23/33",  "23/34",  "23/35",  "23/36",  "23/37",  "23/38",  "23/39",  "23/40",  "23/41",  "23/42",  "23/43",
    "23/44",  "23/45",  "23/47",  "23/48",  "23/49",  "23/50",  "23/51",  "23/52",  "23/53",  "23/54",  "23/55",
    "23/56",  "23/57",  "23/58",  "23/59",  "23/60",  "23/61",  "23/62",  "23/63",  "23/64",  "23/65",  "23/66",
    "23/67",  "23/68",  "23/70",  "23/71",  "23/72",  "23/73",  "23/74",  "23/75",  "23/76",  "23/77",  "23/78",
    "23/79",  "23/80",  "23/81",  "23/82",  "23/83",  "23/84",  "23/85",  "23/86",  "23/87",  "23/88",  "23/89",
    "23/90",  "23/91",  "23/93",  "23/94",  "23/95",  "23/96",  "23/97",  "23/98",  "23/99",  "23/100", "24/25",
    "24/29",  "24/31",  "24/35",  "24/37",  "24/41",  "24/43",  "24/47",  "24/49",  "24/53",  "24/55",  "24/59",
    "24/61",  "24/65",  "24/67",  "24/71",  "24/73",  "24/77",  "24/79",  "24/83",  "24/85",  "24/89",  "24/91",
    "24/95",  "24/97",  "25/26",  "25/27",  "25/28",  "25/29",  "25/31",  "25/32",  "25/33",  "25/34",  "25/36",
    "25/37",  "25/38",  "25/39",  "25/41",  "25/42",  "25/43",  "25/44",  "25/46",  "25/47",  "25/48",  "25/49",
    "25/51",  "25/52",  "25/53",  "25/54",  "25/56",  "25/57",  "25/58",  "25/59",  "25/61",  "25/62",  "25/63",
    "25/64",  "25/66",  "25/67",  "25/68",  "25/69",  "25/71",  "25/72",  "25/73",  "25/74",  "25/76",  "25/77",
    "25/78",  "25/79",  "25/81",  "25/82",  "25/83",  "25/84",  "25/86",  "25/87",  "25/88",  "25/89",  "25/91",
    "25/92",  "25/93",  "25/94",  "25/96",  "25/97",  "25/98",  "25/99",  "26/27",  "26/29",  "26/31",  "26/33",
    "26/35",  "26/37",  "26/41",  "26/43",  "26/45",  "26/47",  "26/49",  "26/51",  "26/53",  "26/55",  "26/57",
    "26/59",  "26/61",  "26/63",  "26/67",  "26/69",  "26/71",  "26/73",  "26/75",  "26/77",  "26/79",  "26/81",
    "26/83",  "26/85",  "26/87",  "26/89",  "26/93",  "26/95",  "26/97",  "26/99",  "27/28",  "27/29",  "27/31",
    "27/32",  "27/34",  "27/35",  "27/37",  "27/38",  "27/40",  "27/41",  "27/43",  "27/44",  "27/46",  "27/47",
    "27/49",  "27/50",  "27/52",  "27/53",  "27/55",  "27/56",  "27/58",  "27/59",  "27/61",  "27/62",  "27/64",
    "27/65",  "27/67",  "27/68",  "27/70",  "27/71",  "27/73",  "27/74",  "27/76",  "27/77",  "27/79",  "27/80",
    "27/82",  "27/83",  "27/85",  "27/86",  "27/88",  "27/89",  "27/91",  "27/92",  "27/94",  "27/95",  "27/97",
    "27/98",  "27/100", "28/29",  "28/31",  "28/33",  "28/37",  "28/39",  "28/41",  "28/43",  "28/45",  "28/47",
    "28/51",  "28/53",  "28/55",  "28/57",  "28/59",  "28/61",  "28/65",  "28/67",  "28/69",  "28/71",  "28/73",
    "28/75",  "28/79",  "28/81",  "28/83",  "28/85",  "28/87",  "28/89",  "28/93",  "28/95",  "28/97",  "28/99",
    "29/30",  "29/31",  "29/32",  "29/33",  "29/34",  "29/35",  "29/36",  "29/37",  "29/38",  "29/39",  "29/40",
    "29/41",  "29/42",  "29/43",  "29/44",  "29/45",  "29/46",  "29/47",  "29/48",  "29/49",  "29/50",  "29/51",
    "29/52",  "29/53",  "29/54",  "29/55",  "29/56",  "29/57",  "29/59",  "29/60",  "29/61",  "29/62",  "29/63",
    "29/64",  "29/65",  "29/66",  "29/67",  "29/68",  "29/69",  "29/70",  "29/71",  "29/72",  "29/73",  "29/74",
    "29/75",  "29/76",  "29/77",  "29/78",  "29/79",  "29/80",  "29/81",  "29/82",  "29/83",  "29/84",  "29/85",
    "29/86",  "29/88",  "29/89",  "29/90",  "29/91",  "29/92",  "29/93",  "29/94",  "29/95",  "29/96",  "29/97",
    "29/98",  "29/99",  "29/100", "30/31",  "30/37",  "30/41",  "30/43",  "30/47",  "30/49",  "30/53",  "30/59",
    "30/61",  "30/67",  "30/71",  "30/73",  "30/77",  "30/79",  "30/83",  "30/89",  "30/91",  "30/97",  "31/32",
    "31/33",  "31/34",  "31/35",  "31/36",  "31/37",  "31/38",  "31/39",  "31/40",  "31/41",  "31/42",  "31/43",
    "31/44",  "31/45",  "31/46",  "31/47",  "31/48",  "31/49",  "31/50",  "31/51",  "31/52",  "31/53",  "31/54",
    "31/55",  "31/56",  "31/57",  "31/58",  "31/59",  "31/60",  "31/61",  "31/63",  "31/64",  "31/65",  "31/66",
    "31/67",  "31/68",  "31/69",  "31/70",  "31/71",  "31/72",  "31/73",  "31/74",  "31/75",  "31/76",  "31/77",
    "31/78",  "31/79",  "31/80",  "31/81",  "31/82",  "31/83",  "31/84",  "31/85",  "31/86",  "31/87",  "31/88",
    "31/89",  "31/90",  "31/91",  "31/92",  "31/94",  "31/95",  "31/96",  "31/97",  "31/98",  "31/99",  "31/100",
    "32/33",  "32/35",  "32/37",  "32/39",  "32/41",  "32/43",  "32/45",  "32/47",  "32/49",  "32/51",  "32/53",
    "32/55",  "32/57",  "32/59",  "32/61",  "32/63",  "32/65",  "32/67",  "32/69",  "32/71",  "32/73",  "32/75",
    "32/77",  "32/79",  "32/81",  "32/83",  "32/85",  "32/87",  "32/89",  "32/91",  "32/93",  "32/95",  "32/97",
    "32/99",  "33/34",  "33/35",  "33/37",  "33/38",  "33/40",  "33/41",  "33/43",  "33/46",  "33/47",  "33/49",
    "33/50",  "33/52",  "33/53",  "33/56",  "33/58",  "33/59",  "33/61",  "33/62",  "33/64",  "33/65",  "33/67",
    "33/68",  "33/70",  "33/71",  "33/73",  "33/74",  "33/76",  "33/79",  "33/80",  "33/82",  "33/83",  "33/85",
    "33/86",  "33/89",  "33/91",  "33/92",  "33/94",  "33/95",  "33/97",  "33/98",  "33/100", "34/35",  "34/37",
    "34/39",  "34/41",  "34/43",  "34/45",  "34/47",  "34/49",  "34/53",  "34/55",  "34/57",  "34/59",  "34/61",
    "34/63",  "34/65",  "34/67",  "34/69",  "34/71",  "34/73",  "34/75",  "34/77",  "34/79",  "34/81",  "34/83",
    "34/87",  "34/89",  "34/91",  "34/93",  "34/95",  "34/97",  "34/99",  "35/36",  "35/37",  "35/38",  "35/39",
    "35/41",  "35/43",  "35/44",  "35/46",  "35/47",  "35/48",  "35/51",  "35/52",  "35/53",  "35/54",  "35/57",
    "35/58",  "35/59",  "35/61",  "35/62",  "35/64",  "35/66",  "35/67",  "35/68",  "35/69",  "35/71",  "35/72",
    "35/73",  "35/74",  "35/76",  "35/78",  "35/79",  "35/81",  "35/82",  "35/83",  "35/86",  "35/87",  "35/88",
    "35/89",  "35/92",  "35/93",  "35/94",  "35/96",  "35/97",  "35/99",  "36/37",  "36/41",  "36/43",  "36/47",
    "36/49",  "36/53",  "36/55",  "36/59",  "36/61",  "36/65",  "36/67",  "36/71",  "36/73",  "36/77",  "36/79",
    "36/83",  "36/85",  "36/89",  "36/91",  "36/95",  "36/97",  "37/38",  "37/39",  "37/40",  "37/41",  "37/42",
    "37/43",  "37/44",  "37/45",  "37/46",  "37/47",  "37/48",  "37/49",  "37/50",  "37/51",  "37/52",  "37/53",
    "37/54",  "37/55",  "37/56",  "37/57",  "37/58",  "37/59",  "37/60",  "37/61",  "37/62",  "37/63",  "37/64",
    "37/65",  "37/66",  "37/67",  "37/68",  "37/69",  "37/70",  "37/71",  "37/72",  "37/73",  "37/75",  "37/76",
    "37/77",  "37/78",  "37/79",  "37/80",  "37/81",  "37/82",  "37/83",  "37/84",  "37/85",  "37/86",  "37/87",
    "37/88",  "37/89",  "37/90",  "37/91",  "37/92",  "37/93",  "37/94",  "37/95",  "37/96",  "37/97",  "37/98",
    "37/99",  "37/100", "38/39",  "38/41",  "38/43",  "38/45",  "38/47",  "38/49",  "38/51",  "38/53",  "38/55",
    "38/59",  "38/61",  "38/63",  "38/65",  "38/67",  "38/69",  "38/71",  "38/73",  "38/75",  "38/77",  "38/79",
    "38/81",  "38/83",  "38/85",  "38/87",  "38/89",  "38/91",  "38/93",  "38/97",  "38/99",  "39/40",  "39/41",
    "39/43",  "39/44",  "39/46",  "39/47",  "39/49",  "39/50",  "39/53",  "39/55",  "39/56",  "39/58",  "39/59",
    "39/61",  "39/62",  "39/64",  "39/67",  "39/68",  "39/70",  "39/71",  "39/73",  "39/74",  "39/76",  "39/77",
    "39/79",  "39/80",  "39/82",  "39/83",  "39/85",  "39/86",  "39/88",  "39/89",  "39/92",  "39/94",  "39/95",
    "39/97",  "39/98",  "39/100", "40/41",  "40/43",  "40/47",  "40/49",  "40/51",  "40/53",  "40/57",  "40/59",
    "40/61",  "40/63",  "40/67",  "40/69",  "40/71",  "40/73",  "40/77",  "40/79",  "40/81",  "40/83",  "40/87",
    "40/89",  "40/91",  "40/93",  "40/97",  "40/99",  "41/42",  "41/43",  "41/44",  "41/45",  "41/46",  "41/47",
    "41/48",  "41/49",  "41/50",  "41/51",  "41/52",  "41/53",  "41/54",  "41/55",  "41/56",  "41/57",  "41/58",
    "41/59",  "41/60",  "41/61",  "41/62",  "41/63",  "41/64",  "41/65",  "41/66",  "41/67",  "41/68",  "41/69",
    "41/70",  "41/71",  "41/72",  "41/73",  "41/74",  "41/75",  "41/76",  "41/77",  "41/78",  "41/79",  "41/80",
    "41/81",  "41/83",  "41/84",  "41/85",  "41/86",  "41/87",  "41/88",  "41/89",  "41/90",  "41/91",  "41/92",
    "41/93",  "41/94",  "41/95",  "41/96",  "41/97",  "41/98",  "41/99",  "41/100", "42/43",  "42/47",  "42/53",
    "42/55",  "42/59",  "42/61",  "42/65",  "42/67",  "42/71",  "42/73",  "42/79",  "42/83",  "42/85",  "42/89",
    "42/95",  "42/97",  "43/44",  "43/45",  "43/46",  "43/47",  "43/48",  "43/49",  "43/50",  "43/51",  "43/52",
    "43/53",  "43/54",  "43/55",  "43/56",  "43/57",  "43/58",  "43/59",  "43/60",  "43/61",  "43/62",  "43/63",
    "43/64",  "43/65",  "43/66",  "43/67",  "43/68",  "43/69",  "43/70",  "43/71",  "43/72",  "43/73",  "43/74",
    "43/75",  "43/76",  "43/77",  "43/78",  "43/79",  "43/80",  "43/81",  "43/82",  "43/83",  "43/84",  "43/85",
    "43/87",  "43/88",  "43/89",  "43/90",  "43/91",  "43/92",  "43/93",  "43/94",  "43/95",  "43/96",  "43/97",
    "43/98",  "43/99",  "43/100", "44/45",  "44/47",  "44/49",  "44/51",  "44/53",  "44/57",  "44/59",  "44/61",
    "44/63",  "44/65",  "44/67",  "44/69",  "44/71",  "44/73",  "44/75",  "44/79",  "44/81",  "44/83",  "44/85",
    "44/87",  "44/89",  "44/91",  "44/93",  "44/95",  "44/97",  "45/46",  "45/47",  "45/49",  "45/52",  "45/53",
    "45/56",  "45/58",  "45/59",  "45/61",  "45/62",  "45/64",  "45/67",  "45/68",  "45/71",  "45/73",  "45/74",
    "45/76",  "45/77",  "45/79",  "45/82",  "45/83",  "45/86",  "45/88",  "45/89",  "45/91",  "45/92",  "45/94",
    "45/97",  "45/98",  "46/47",  "46/49",  "46/51",  "46/53",  "46/55",  "46/57",  "46/59",  "46/61",  "46/63",
    "46/65",  "46/67",  "46/71",  "46/73",  "46/75",  "46/77",  "46/79",  "46/81",  "46/83",  "46/85",  "46/87",
    "46/89",  "46/91",  "46/93",  "46/95",  "46/97",  "46/99",  "47/48",  "47/49",  "47/50",  "47/51",  "47/52",
    "47/53",  "47/54",  "47/55",  "47/56",  "47/57",  "47/58",  "47/59",  "47/60",  "47/61",  "47/62",  "47/63",
    "47/64",  "47/65",  "47/66",  "47/67",  "47/68",  "47/69",  "47/70",  "47/71",  "47/72",  "47/73",  "47/74",
    "47/75",  "47/76",  "47/77",  "47/78",  "47/79",  "47/80",  "47/81",  "47/82",  "47/83",  "47/84",  "47/85",
    "47/86",  "47/87",  "47/88",  "47/89",  "47/90",  "47/91",  "47/92",  "47/93",  "47/95",  "47/96",  "47/97",
    "47/98",  "47/99",  "47/100", "48/49",  "48/53",  "48/55",  "48/59",  "48/61",  "48/65",  "48/67",  "48/71",
    "48/73",  "48/77",  "48/79",  "48/83",  "48/85",  "48/89",  "48/91",  "48/95",  "48/97",  "49/50",  "49/51",
    "49/52",  "49/53",  "49/54",  "49/55",  "49/57",  "49/58",  "49/59",  "49/60",  "49/61",  "49/62",  "49/64",
    "49/65",  "49/66",  "49/67",  "49/68",  "49/69",  "49/71",  "49/72",  "49/73",  "49/74",  "49/75",  "49/76",
    "49/78",  "49/79",  "49/80",  "49/81",  "49/82",  "49/83",  "49/85",  "49/86",  "49/87",  "49/88",  "49/89",
    "49/90",  "49/92",  "49/93",  "49/94",  "49/95",  "49/96",  "49/97",  "49/99",  "49/100", "50/51",  "50/53",
    "50/57",  "50/59",  "50/61",  "50/63",  "50/67",  "50/69",  "50/71",  "50/73",  "50/77",  "50/79",  "50/81",
    "50/83",  "50/87",  "50/89",  "50/91",  "50/93",  "50/97",  "50/99",  "51/52",  "51/53",  "51/55",  "51/56",
    "51/58",  "51/59",  "51/61",  "51/62",  "51/64",  "51/65",  "51/67",  "51/70",  "51/71",  "51/73",  "51/74",
    "51/76",  "51/77",  "51/79",  "51/80",  "51/82",  "51/83",  "51/86",  "51/88",  "51/89",  "51/91",  "51/92",
    "51/94",  "51/95",  "51/97",  "51/98",  "51/100", "52/53",  "52/55",  "52/57",  "52/59",  "52/61",  "52/63",
    "52/67",  "52/69",  "52/71",  "52/73",  "52/75",  "52/77",  "52/79",  "52/81",  "52/83",  "52/85",  "52/87",
    "52/89",  "52/93",  "52/95",  "52/97",  "52/99",  "53/54",  "53/55",  "53/56",  "53/57",  "53/58",  "53/59",
    "53/60",  "53/61",  "53/62",  "53/63",  "53/64",  "53/65",  "53/66",  "53/67",  "53/68",  "53/69",  "53/70",
    "53/71",  "53/72",  "53/73",  "53/74",  "53/75",  "53/76",  "53/77",  "53/78",  "53/79",  "53/80",  "53/81",
    "53/82",  "53/83",  "53/84",  "53/85",  "53/86",  "53/87",  "53/88",  "53/89",  "53/90",  "53/91",  "53/92",
    "53/93",  "53/94",  "53/95",  "53/96",  "53/97",  "53/98",  "53/99",  "53/100", "54/55",  "54/59",  "54/61",
    "54/65",  "54/67",  "54/71",  "54/73",  "54/77",  "54/79",  "54/83",  "54/85",  "54/89",  "54/91",  "54/95",
    "54/97",  "55/56",  "55/57",  "55/58",  "55/59",  "55/61",  "55/62",  "55/63",  "55/64",  "55/67",  "55/68",
    "55/69",  "55/71",  "55/72",  "55/73",  "55/74",  "55/76",  "55/78",  "55/79",  "55/81",  "55/82",  "55/83",
    "55/84",  "55/86",  "55/87",  "55/89",  "55/91",  "55/92",  "55/93",  "55/94",  "55/96",  "55/97",  "55/98",
    "56/57",  "56/59",  "56/61",  "56/65",  "56/67",  "56/69",  "56/71",  "56/73",  "56/75",  "56/79",  "56/81",
    "56/83",  "56/85",  "56/87",  "56/89",  "56/93",  "56/95",  "56/97",  "56/99",  "57/58",  "57/59",  "57/61",
    "57/62",  "57/64",  "57/65",  "57/67",  "57/68",  "57/70",  "57/71",  "57/73",  "57/74",  "57/77",  "57/79",
    "57/80",  "57/82",  "57/83",  "57/85",  "57/86",  "57/88",  "57/89",  "57/91",  "57/92",  "57/94",  "57/97",
    "57/98",  "57/100", "58/59",  "58/61",  "58/63",  "58/65",  "58/67",  "58/69",  "58/71",  "58/73",  "58/75",
    "58/77",  "58/79",  "58/81",  "58/83",  "58/85",  "58/89",  "58/91",  "58/93",  "58/95",  "58/97",  "58/99",
    "59/60",  "59/61",  "59/62",  "59/63",  "59/64",  "59/65",  "59/66",  "59/67",  "59/68",  "59/69",  "59/70",
    "59/71",  "59/72",  "59/73",  "59/74",  "59/75",  "59/76",  "59/77",  "59/78",  "59/79",  "59/80",  "59/81",
    "59/82",  "59/83",  "59/84",  "59/85",  "59/86",  "59/87",  "59/88",  "59/89",  "59/90",  "59/91",  "59/92",
    "59/93",  "59/94",  "59/95",  "59/96",  "59/97",  "59/98",  "59/99",  "59/100", "60/61",  "60/67",  "60/71",
    "60/73",  "60/77",  "60/79",  "60/83",  "60/89",  "60/91",  "60/97",  "61/62",  "61/63",  "61/64",  "61/65",
    "61/66",  "61/67",  "61/68",  "61/69",  "61/70",  "61/71",  "61/72",  "61/73",  "61/74",  "61/75",  "61/76",
    "61/77",  "61/78",  "61/79",  "61/80",  "61/81",  "61/82",  "61/83",  "61/84",  "61/85",  "61/86",  "61/87",
    "61/88",  "61/89",  "61/90",  "61/91",  "61/92",  "61/93",  "61/94",  "61/95",  "61/96",  "61/97",  "61/98",
    "61/99",  "61/100", "62/63",  "62/65",  "62/67",  "62/69",  "62/71",  "62/73",  "62/75",  "62/77",  "62/79",
    "62/81",  "62/83",  "62/85",  "62/87",  "62/89",  "62/91",  "62/95",  "62/97",  "62/99",  "63/64",  "63/65",
    "63/67",  "63/68",  "63/71",  "63/73",  "63/74",  "63/76",  "63/79",  "63/80",  "63/82",  "63/83",  "63/85",
    "63/86",  "63/88",  "63/89",  "63/92",  "63/94",  "63/95",  "63/97",  "63/100", "64/65",  "64/67",  "64/69",
    "64/71",  "64/73",  "64/75",  "64/77",  "64/79",  "64/81",  "64/83",  "64/85",  "64/87",  "64/89",  "64/91",
    "64/93",  "64/95",  "64/97",  "64/99",  "65/66",  "65/67",  "65/68",  "65/69",  "65/71",  "65/72",  "65/73",
    "65/74",  "65/76",  "65/77",  "65/79",  "65/81",  "65/82",  "65/83",  "65/84",  "65/86",  "65/87",  "65/88",
    "65/89",  "65/92",  "65/93",  "65/94",  "65/96",  "65/97",  "65/98",  "65/99",  "66/67",  "66/71",  "66/73",
    "66/79",  "66/83",  "66/85",  "66/89",  "66/91",  "66/95",  "66/97",  "67/68",  "67/69",  "67/70",  "67/71",
    "67/72",  "67/73",  "67/74",  "67/75",  "67/76",  "67/77",  "67/78",  "67/79",  "67/80",  "67/81",  "67/82",
    "67/83",  "67/84",  "67/85",  "67/86",  "67/87",  "67/88",  "67/89",  "67/90",  "67/91",  "67/92",  "67/93",
    "67/94",  "67/95",  "67/96",  "67/97",  "67/98",  "67/99",  "67/100", "68/69",  "68/71",  "68/73",  "68/75",
    "68/77",  "68/79",  "68/81",  "68/83",  "68/87",  "68/89",  "68/91",  "68/93",  "68/95",  "68/97",  "68/99",
    "69/70",  "69/71",  "69/73",  "69/74",  "69/76",  "69/77",  "69/79",  "69/80",  "69/82",  "69/83",  "69/85",
    "69/86",  "69/88",  "69/89",  "69/91",  "69/94",  "69/95",  "69/97",  "69/98",  "69/100", "70/71",  "70/73",
    "70/79",  "70/81",  "70/83",  "70/87",  "70/89",  "70/93",  "70/97",  "70/99",  "71/72",  "71/73",  "71/74",
    "71/75",  "71/76",  "71/77",  "71/78",  "71/79",  "71/80",  "71/81",  "71/82",  "71/83",  "71/84",  "71/85",
    "71/86",  "71/87",  "71/88",  "71/89",  "71/90",  "71/91",  "71/92",  "71/93",  "71/94",  "71/95",  "71/96",
    "71/97",  "71/98",  "71/99",  "71/100", "72/73",  "72/77",  "72/79",  "72/83",  "72/85",  "72/89",  "72/91",
    "72/95",  "72/97",  "73/74",  "73/75",  "73/76",  "73/77",  "73/78",  "73/79",  "73/80",  "73/81",  "73/82",
    "73/83",  "73/84",  "73/85",  "73/86",  "73/87",  "73/88",  "73/89",  "73/90",  "73/91",  "73/92",  "73/93",
    "73/94",  "73/95",  "73/96",  "73/97",  "73/98",  "73/99",  "73/100", "74/75",  "74/77",  "74/79",  "74/81",
    "74/83",  "74/85",  "74/87",  "74/89",  "74/91",  "74/93",  "74/95",  "74/97",  "74/99",  "75/76",  "75/77",
    "75/79",  "75/82",  "75/83",  "75/86",  "75/88",  "75/89",  "75/91",  "75/92",  "75/94",  "75/97",  "75/98",
    "76/77",  "76/79",  "76/81",  "76/83",  "76/85",  "76/87",  "76/89",  "76/91",  "76/93",  "76/97",  "76/99",
    "77/78",  "77/79",  "77/80",  "77/81",  "77/82",  "77/83",  "77/85",  "77/86",  "77/87",  "77/89",  "77/90",
    "77/92",  "77/93",  "77/94",  "77/95",  "77/96",  "77/97",  "77/100", "78/79",  "78/83",  "78/85",  "78/89",
    "78/95",  "78/97",  "79/80",  "79/81",  "79/82",  "79/83",  "79/84",  "79/85",  "79/86",  "79/87",  "79/88",
    "79/89",  "79/90",  "79/91",  "79/92",  "79/93",  "79/94",  "79/95",  "79/96",  "79/97",  "79/98",  "79/99",
    "79/100", "80/81",  "80/83",  "80/87",  "80/89",  "80/91",  "80/93",  "80/97",  "80/99",  "81/82",  "81/83",
    "81/85",  "81/86",  "81/88",  "81/89",  "81/91",  "81/92",  "81/94",  "81/95",  "81/97",  "81/98",  "81/100",
    "82/83",  "82/85",  "82/87",  "82/89",  "82/91",  "82/93",  "82/95",  "82/97",  "82/99",  "83/84",  "83/85",
    "83/86",  "83/87",  "83/88",  "83/89",  "83/90",  "83/91",  "83/92",  "83/93",  "83/94",  "83/95",  "83/96",
    "83/97",  "83/98",  "83/99",  "83/100", "84/85",  "84/89",  "84/95",  "84/97",  "85/86",  "85/87",  "85/88",
    "85/89",  "85/91",  "85/92",  "85/93",  "85/94",  "85/96",  "85/97",  "85/98",  "85/99",  "86/87",  "86/89",
    "86/91",  "86/93",  "86/95",  "86/97",  "86/99",  "87/88",  "87/89",  "87/91",  "87/92",  "87/94",  "87/95",
    "87/97",  "87/98",  "87/100", "88/89",  "88/91",  "88/93",  "88/95",  "88/97",  "89/90",  "89/91",  "89/92",
    "89/93",  "89/94",  "89/95",  "89/96",  "89/97",  "89/98",  "89/99",  "89/100", "90/91",  "90/97",  "91/92",
    "91/93",  "91/94",  "91/95",  "91/96",  "91/97",  "91/99",  "91/100", "92/93",  "92/95",  "92/97",  "92/99",
    "93/94",  "93/95",  "93/97",  "93/98",  "93/100", "94/95",  "94/97",  "94/99",  "95/96",  "95/97",  "95/98",
    "95/99",  "96/97",  "97/98",  "97/99",  "97/100", "98/99",  "99/100"
};