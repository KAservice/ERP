#ifndef UObject1CVnCompCOMImplH
#define UObject1CVnCompCOMImplH
#include "IObject1CVnCompCOM.h"
#include "UObject1CVnCompCOM.h"

//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TObject1CVnCompCOMImpl)) TObject1CVnCompCOMImpl : public IObject1CVnCompCOM
{
public:
   TObject1CVnCompCOMImpl();
   ~TObject1CVnCompCOMImpl();
   TObject1CVnCompCOM * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);


//IObject1CVnComp
   virtual wchar_t  * get_ProgIdCOMObject(void);
   virtual void set_ProgIdCOMObject(wchar_t  * ProgIdCOMObject);

   virtual bool InitVC();
   virtual void DoneVC();



//      ILanguageExtender : public IUnknown

		virtual bool RegisterExtensionAs(
			/* [out][in] */ wchar_t *bstrExtensionName);

		virtual bool GetNProps(
			/* [out][in] */ long *plProps);

		virtual bool FindProp(
			/* [in] */ wchar_t * bstrPropName,
			/* [out][in] */ long *plPropNum);

		virtual bool GetPropName(
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
			/* [out][in] */ wchar_t *pbstrPropName);

		virtual bool GetPropVal(
            /* [in] */ long lPropNum,
			/* [out][in] */ TkasVariant *pvarPropVal);

		virtual bool SetPropVal(
            /* [in] */ long lPropNum,
			/* [in] */ TkasVariant *varPropVal);

		virtual bool IsPropReadable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropRead);

		virtual bool IsPropWritable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropWrite);

		virtual bool GetNMethods(
			/* [out][in] */ long *plMethods);

		virtual bool FindMethod(
            wchar_t * bstrMethodName,
			/* [out][in] */ long *plMethodNum);

		virtual bool GetMethodName(
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
			/* [out][in] */ wchar_t *pbstrMethodName);

		virtual bool GetNParams(
            /* [in] */ long lMethodNum,
			/* [out][in] */ long *plParams);

		virtual bool GetParamDefValue(
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
			/* [out][in] */ TkasVariant *pvarParamDefValue);

		virtual bool HasRetVal(
            /* [in] */ long lMethodNum,
			/* [out][in] */ bool *pboolRetValue);

		virtual bool CallAsProc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray);

        virtual bool CallAsFunc(
            /* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *pvarRetValue,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray);




};
#define CLSID_TObject1CVnCompCOMImpl __uuidof(TObject1CVnCompCOMImpl)
#endif
