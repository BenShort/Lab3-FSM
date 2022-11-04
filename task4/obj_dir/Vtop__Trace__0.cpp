// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,((0U != vlSelf->top__DOT__f1_fsm_block__DOT__current_state)));
        bufp->chgBit(oldp+1,((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)));
        bufp->chgBit(oldp+2,(vlSelf->top__DOT__tick));
        bufp->chgBit(oldp+3,(((0U != vlSelf->top__DOT__delay_block__DOT__current_state) 
                              & ((1U != vlSelf->top__DOT__delay_block__DOT__current_state) 
                                 & (2U == vlSelf->top__DOT__delay_block__DOT__current_state)))));
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__lfsr_block__DOT__sreg),7);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__clktick_block__DOT__count),5);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__delay_block__DOT__count),7);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__delay_block__DOT__current_state),32);
        bufp->chgIData(oldp+8,(((0U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                 ? ((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                     ? 1U : vlSelf->top__DOT__delay_block__DOT__current_state)
                                 : ((1U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                     ? ((0U == (IData)(vlSelf->top__DOT__delay_block__DOT__count))
                                         ? 2U : vlSelf->top__DOT__delay_block__DOT__current_state)
                                     : ((2U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                         ? ((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                             ? 3U : 0U)
                                         : ((3U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                             ? ((8U 
                                                 == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                                 ? vlSelf->top__DOT__delay_block__DOT__current_state
                                                 : 0U)
                                             : 0U))))),32);
        bufp->chgBit(oldp+9,(vlSelf->top__DOT____Vcellinp__f1_fsm_block__en));
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__f1_fsm_block__DOT__current_state),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__f1_fsm_block__DOT__next_state),32);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__lfsr_block__DOT__sreg),7);
    }
    bufp->chgBit(oldp+13,(vlSelf->rst));
    bufp->chgBit(oldp+14,(vlSelf->clk));
    bufp->chgBit(oldp+15,(vlSelf->trigger));
    bufp->chgCData(oldp+16,(vlSelf->bin),8);
    bufp->chgSData(oldp+17,(vlSelf->BCD),12);
    bufp->chgCData(oldp+18,(vlSelf->data_out),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
