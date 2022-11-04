// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+14,"rst", false,-1);
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+16,"trigger", false,-1);
    tracep->declBus(c+17,"bin", false,-1, 7,0);
    tracep->declBus(c+18,"BCD", false,-1, 11,0);
    tracep->declBus(c+19,"data_out", false,-1, 7,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+14,"rst", false,-1);
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+16,"trigger", false,-1);
    tracep->declBus(c+17,"bin", false,-1, 7,0);
    tracep->declBus(c+18,"BCD", false,-1, 11,0);
    tracep->declBus(c+19,"data_out", false,-1, 7,0);
    tracep->declBit(c+1,"cmd_seq", false,-1);
    tracep->declBit(c+2,"cmd_delay", false,-1);
    tracep->declBit(c+3,"tick", false,-1);
    tracep->declBit(c+4,"time_out", false,-1);
    tracep->declBus(c+5,"k", false,-1, 6,0);
    tracep->pushNamePrefix("clktick_block ");
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+14,"rst", false,-1);
    tracep->declBit(c+1,"en", false,-1);
    tracep->declBus(c+20,"N", false,-1, 4,0);
    tracep->declBit(c+3,"tick", false,-1);
    tracep->declBus(c+6,"count", false,-1, 4,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("delay_block ");
    tracep->declBus(c+21,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+14,"rst", false,-1);
    tracep->declBit(c+2,"trigger", false,-1);
    tracep->declBus(c+5,"n", false,-1, 6,0);
    tracep->declBit(c+4,"time_out", false,-1);
    tracep->declBus(c+7,"count", false,-1, 6,0);
    tracep->declBus(c+8,"current_state", false,-1, 31,0);
    tracep->declBus(c+9,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("f1_fsm_block ");
    tracep->declBit(c+14,"rst", false,-1);
    tracep->declBit(c+10,"en", false,-1);
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+16,"trigger", false,-1);
    tracep->declBus(c+19,"data_out", false,-1, 7,0);
    tracep->declBit(c+1,"cmd_seq", false,-1);
    tracep->declBit(c+2,"cmd_delay", false,-1);
    tracep->declBus(c+11,"current_state", false,-1, 31,0);
    tracep->declBus(c+12,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lfsr_block ");
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+22,"rst", false,-1);
    tracep->declBit(c+23,"en", false,-1);
    tracep->declBus(c+5,"data_out", false,-1, 6,0);
    tracep->declBus(c+13,"sreg", false,-1, 7,1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,((0U != vlSelf->top__DOT__f1_fsm_block__DOT__current_state)));
    bufp->fullBit(oldp+2,((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__tick));
    bufp->fullBit(oldp+4,(((0U != vlSelf->top__DOT__delay_block__DOT__current_state) 
                           & ((1U != vlSelf->top__DOT__delay_block__DOT__current_state) 
                              & (2U == vlSelf->top__DOT__delay_block__DOT__current_state)))));
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__lfsr_block__DOT__sreg),7);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__clktick_block__DOT__count),5);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__delay_block__DOT__count),7);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__delay_block__DOT__current_state),32);
    bufp->fullIData(oldp+9,(((0U == vlSelf->top__DOT__delay_block__DOT__current_state)
                              ? ((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                  ? 1U : vlSelf->top__DOT__delay_block__DOT__current_state)
                              : ((1U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                  ? ((0U == (IData)(vlSelf->top__DOT__delay_block__DOT__count))
                                      ? 2U : vlSelf->top__DOT__delay_block__DOT__current_state)
                                  : ((2U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                      ? ((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                          ? 3U : 0U)
                                      : ((3U == vlSelf->top__DOT__delay_block__DOT__current_state)
                                          ? ((8U == vlSelf->top__DOT__f1_fsm_block__DOT__current_state)
                                              ? vlSelf->top__DOT__delay_block__DOT__current_state
                                              : 0U)
                                          : 0U))))),32);
    bufp->fullBit(oldp+10,(vlSelf->top__DOT____Vcellinp__f1_fsm_block__en));
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__f1_fsm_block__DOT__current_state),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__f1_fsm_block__DOT__next_state),32);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__lfsr_block__DOT__sreg),7);
    bufp->fullBit(oldp+14,(vlSelf->rst));
    bufp->fullBit(oldp+15,(vlSelf->clk));
    bufp->fullBit(oldp+16,(vlSelf->trigger));
    bufp->fullCData(oldp+17,(vlSelf->bin),8);
    bufp->fullSData(oldp+18,(vlSelf->BCD),12);
    bufp->fullCData(oldp+19,(vlSelf->data_out),8);
    bufp->fullCData(oldp+20,(0xeU),5);
    bufp->fullIData(oldp+21,(7U),32);
    bufp->fullBit(oldp+22,(0U));
    bufp->fullBit(oldp+23,(1U));
}
