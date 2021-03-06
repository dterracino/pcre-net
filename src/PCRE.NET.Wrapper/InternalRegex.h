
#pragma once

#include "JitCompileOptions.h"
#include "CompileContext.h"
#include "MatchContext.h"

namespace PCRE {
	namespace Wrapper {

		enum struct PatternOptions : unsigned int;
		enum struct InfoKey;
		ref class CalloutInfo;

		public ref class InternalRegex sealed
		{
		public:
			InternalRegex(CompileContext^ context);
			~InternalRegex();
			!InternalRegex();

			MatchData^ __clrcall Match(MatchContext^ context);
			MatchData^ __clrcall DfaMatch(MatchContext^ context);

			int GetInfoInt32(InfoKey key);

			property int CaptureCount {
				int get() { return _captureCount; }
			}

			property System::Collections::Generic::IDictionary<System::String^, array<int>^>^ CaptureNames {
				System::Collections::Generic::IDictionary<System::String^, array<int>^>^ get() { return _captureNames; }
			}

			property System::Collections::Generic::IList<CalloutInfo^>^ Callouts {
				System::Collections::Generic::IList<CalloutInfo^>^ get();
			}

		internal:
			property pcre2_code* Code {
				pcre2_code* get() { return _re; }
			}

			CalloutInfo^ GetCalloutInfoByPatternPosition(int position);

		private:
			pcre2_code* _re;
			initonly int _captureCount;
			initonly System::Collections::Generic::Dictionary<System::String^, array<int>^>^ _captureNames;
			System::Collections::Generic::IList<CalloutInfo^>^ _callouts;
			System::Collections::Generic::Dictionary<int, CalloutInfo^>^ _calloutInfoByPatternPosition;
		};
	}
}
