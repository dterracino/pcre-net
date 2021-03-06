﻿using System;
using PCRE.Wrapper;

namespace PCRE
{
    [Flags]
    public enum PcreMatchOptions : long
    {
        None = 0,

        Anchored = PatternOptions.Anchored,

        NotBol = PatternOptions.NotBol,
        NotEol = PatternOptions.NotEol,
        NotEmpty = PatternOptions.NotEmpty,
        NotEmptyAtStart = PatternOptions.NotEmptyAtStart,

        NoStartOptimize = PatternOptions.NoStartOptimize,

        PartialSoft = PatternOptions.PartialSoft,
        PartialHard = PatternOptions.PartialHard,

        NoUtfCheck = PatternOptions.NoUtfCheck
    }
}
