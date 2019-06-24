#ifndef UIObject1CVnCompCOMH
#define UIObject1CVnCompCOMH


#define ProgId_Object1CVnCompCOM  "Kas.Object1CVnCompCOM.1"
#define Global_CLSID_TObject1CVnCompCOMImpl "{F46572D4-FCB1-44C1-9356-E9BF7599AA47}"
#define Global_IID_IObject1CVnCompCOM  "{82C71AFC-212F-4790-9E22-FE496E8FF8CC}"


#include <GlobalInterface.h>
#include <UkasVariant.h>
//#include <oaidl.h>

class __declspec(uuid(Global_IID_IObject1CVnCompCOM)) IObject1CVnCompCOM : public IkanUnknown
{
public:
   __property wchar_t  * ProgIdCOMObject = {read = get_ProgIdCOMObject , write = set_ProgIdCOMObject};
   virtual wchar_t  * get_ProgIdCOMObject(void)=0;
   virtual void set_ProgIdCOMObject(wchar_t  * ProgIdCOMObject)=0;

   virtual bool InitVC()=0;
   virtual void DoneVC()=0;



//      ILanguageExtender : public IUnknown

		virtual bool RegisterExtensionAs(
			/* [out][in] */ wchar_t *bstrExtensionName) = 0;

		virtual bool GetNProps(
			/* [out][in] */ long *plProps) = 0;

		virtual bool FindProp(
			/* [in] */ wchar_t * bstrPropName,
            /* [out][in] */ long *plPropNum) = 0;

		virtual bool GetPropName(
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
			/* [out][in] */ wchar_t *pbstrPropName) = 0;

		virtual bool GetPropVal(
            /* [in] */ long lPropNum,
			/* [out][in] */ TkasVariant *pvarPropVal) = 0;

		virtual bool SetPropVal(
            /* [in] */ long lPropNum,
			/* [in] */ TkasVariant *varPropVal) = 0;

		virtual bool IsPropReadable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropRead) = 0;

		virtual bool IsPropWritable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropWrite) = 0;

		virtual bool GetNMethods(
            /* [out][in] */ long *plMethods) = 0;

		virtual bool FindMethod(
            wchar_t * bstrMethodName,
            /* [out][in] */ long *plMethodNum) = 0;

		virtual bool GetMethodName(
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
			/* [out][in] */ wchar_t *pbstrMethodName) = 0;

		virtual bool GetNParams(
            /* [in] */ long lMethodNum,
            /* [out][in] */ long *plParams) = 0;

		virtual bool GetParamDefValue(
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
			/* [out][in] */ TkasVariant *pvarParamDefValue) = 0;

		virtual bool HasRetVal(
            /* [in] */ long lMethodNum,
			/* [out][in] */ bool *pboolRetValue) = 0;

		virtual bool CallAsProc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray) = 0;

        virtual bool CallAsFunc(
            /* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *pvarRetValue,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray) = 0;





};
#define IID_IObject1CVnCompCOM __uuidof(IObject1CVnCompCOM)
#endif
